#pragma once

#include <vector>

namespace otp {

unsigned char encrypt(unsigned char plaintext, unsigned char key);
unsigned char decrypt(unsigned char ciphertext, unsigned char key);

}
