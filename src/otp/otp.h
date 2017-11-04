#pragma once

#include <vector>

#include "otp_macros.h"

namespace otp {

OTP_EXPORT const unsigned char MIN = 'A';
OTP_EXPORT const unsigned char MAX = 'Z';

OTP_EXPORT unsigned char encrypt(unsigned char plaintext, unsigned char key);
OTP_EXPORT unsigned char decrypt(unsigned char ciphertext, unsigned char key);

}  // namespace otp
