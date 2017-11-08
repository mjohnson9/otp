#include <cstdint>
#include <iostream>

#include <gflags/gflags.h>

#include "otp/otp.h"

int main(int argc, char* argv[]) {
  gflags::SetUsageMessage("generate OTP key material");
  gflags::ParseCommandLineFlags(&argc, &argv, true);
  return 0;
}
