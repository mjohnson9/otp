#include "otp/otp.h"

#include <vector>

#include "gtest/gtest.h"

namespace otp {

TEST(otp, reciprocity) {
  for (unsigned char key = MIN; key <= MAX; key++) {
    for (unsigned char plaintext = MIN; key <= MAX; key++) {
      EXPECT_EQ(decrypt(encrypt(plaintext, key), key), plaintext);
    }
  }
}

TEST(encrypt, valid_output) {
  for (unsigned char key = MIN; key <= MAX; key++) {
    for (unsigned char plaintext = MIN; key <= MAX; key++) {
      unsigned char ciphertext = encrypt(plaintext, key);
      EXPECT_GE(ciphertext, otp::MIN);
      EXPECT_LE(ciphertext, otp::MAX);
    }
  }
}

TEST(decrypt, valid_output) {
  for (unsigned char key = MIN; key <= MAX; key++) {
    for (unsigned char ciphertext = MIN; key <= MAX; key++) {
      unsigned char plaintext = decrypt(ciphertext, key);
      EXPECT_GE(plaintext, otp::MIN);
      EXPECT_LE(plaintext, otp::MAX);
    }
  }
}

}  // namespace otp

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
