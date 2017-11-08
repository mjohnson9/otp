#include <climits>
#include <cstdint>
#include <iostream>
#include <random>

#include <gflags/gflags.h>

#include "otp/otp.h"

DEFINE_uint64(characters, 80 * 16, "Number of characters to generate");

int main(int argc, char* argv[]) {
  gflags::SetUsageMessage("generate OTP key material");
  gflags::ParseCommandLineFlags(&argc, &argv, true);

  std::random_device seeder;
  std::uniform_int_distribution<unsigned int> seederDist(0, UINT_MAX);

  std::default_random_engine rand(seederDist(seeder));
  std::uniform_int_distribution<unsigned char> dist(otp::MIN, otp::MAX);

  for (unsigned long i = 0; i < FLAGS_characters; i++) {
    unsigned char c = dist(rand);
    std::cout << c;
  }

  std::cout << std::endl;
  std::cout.flush();

  return 0;
}
