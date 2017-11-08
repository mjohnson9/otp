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

}  // namespace otp

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
