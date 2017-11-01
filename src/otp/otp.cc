#include "otp/otp.h"

namespace {
const unsigned char NUM_CHARS = otp::MAX - otp::MIN;

unsigned char to_internal(unsigned char c) { return c - otp::MIN; }

unsigned char from_internal(unsigned char c) { return c + otp::MIN; }
}  // namespace

namespace otp {

unsigned char encrypt(unsigned char plaintext, unsigned char key) {
  unsigned char internalPlaintext = to_internal(plaintext);
  unsigned char internalKey = to_internal(key);

  return from_internal((internalPlaintext + internalKey) % NUM_CHARS);
}

unsigned char decrypt(unsigned char ciphertext, unsigned char key) {
  unsigned char internalCiphertext = to_internal(ciphertext);
  unsigned char internalKey = to_internal(key);

  return from_internal((internalCiphertext - internalKey) % NUM_CHARS);
}

}  // namespace otp
