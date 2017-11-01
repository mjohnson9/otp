#include <cstdint>
#include <iostream>
#include <string>

#include "glog/logging.h"

int main(int, char* argv[]) {
  google::InitGoogleLogging(argv[0]);

  LOG(INFO) << "Test";

  return 0;
}
