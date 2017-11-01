#pragma once

#include <vector>

namespace otp {

const unsigned char MIN = 'A';
const unsigned char MAX = 'Z';

unsigned char encrypt(unsigned char plaintext, unsigned char key);
unsigned char decrypt(unsigned char ciphertext, unsigned char key);

}  // namespace otp
