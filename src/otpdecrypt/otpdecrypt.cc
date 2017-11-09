#include <cstdint>
#include <fstream>
#include <iostream>
#include <string>

#include "gflags/gflags.h"

#include "otp/otp.h"

DEFINE_string(key_file, "key.txt", "file to use for key content");
DEFINE_uint64(key_offset, 0, "offset from the beginning of the key content");

bool validate_input_phrase(std::string s);
bool decrypt_and_output(std::istream* key_material, std::string s);
std::ifstream* open_key_file(std::string filePath);

int main(int argc, char* argv[]) {
  gflags::SetUsageMessage(std::string("decrypt a phrase using OTP\n") +
                          std::string("example usage: ") +
                          std::string(argv[0]) +
                          std::string(" <input phrase>"));
  gflags::ParseCommandLineFlags(&argc, &argv, true);

  if (argc < 2) {
    std::cerr << "missing input phrase" << std::endl << std::endl;
    gflags::ShowUsageWithFlags(argv[0]);
    return 64;
  }

  std::string input(argv[1]);

  if (!validate_input_phrase(input)) {
    gflags::ShowUsageWithFlags(argv[0]);
    return 64;
  }

  std::ifstream* key_file = open_key_file(FLAGS_key_file);
  if (key_file == NULL) {
    gflags::ShowUsageWithFlags(argv[0]);
    return 1;
  }

  key_file->seekg(FLAGS_key_offset);
  if (key_file->eof()) {
    std::cerr
        << "failed to seek to key material offset: not enough key material"
        << std::endl;
    return 1;
  } else if (key_file->fail()) {
    std::cerr << "failed to seek to key material offset: "
              << std::strerror(errno) << std::endl
              << std::endl;
    return 1;
  }

  if (!decrypt_and_output(key_file, input)) {
    key_file->close();
    return 1;
  }

  key_file->close();

  return 0;
}

bool validate_input_phrase(std::string s) {
  for (auto c : s) {
    if (c < otp::MIN || c > otp::MAX) {
      std::cerr << "invalid input character: " << c << std::endl << std::endl;
      return false;
    }
  }
  return true;
}

std::ifstream* open_key_file(std::string filePath) {
  std::ifstream* f = new std::ifstream();
  f->open(filePath);
  if (!f->is_open()) {
    std::cerr << "failed to open key material file: " << std::strerror(errno)
              << std::endl
              << std::endl;
    return NULL;
  }

  return f;
}

bool decrypt_and_output(std::istream* key_material, std::string s) {
  unsigned char key = '\0';
  for (auto ciphertext : s) {
    do {
      (*key_material) >> key;
      if (key_material->eof()) {
        std::cerr << "failed to read key material: unexpected end of file"
                  << std::endl;
        return false;
      } else if (key_material->fail()) {
        std::cerr << "failed to read key material: " << std::strerror(errno)
                  << std::endl;
        return false;
      }
    } while (key < otp::MIN || key > otp::MAX);

    std::cout << otp::decrypt(ciphertext, key);
  }

  std::cout << std::endl;
  std::cout.flush();

  return true;
}
