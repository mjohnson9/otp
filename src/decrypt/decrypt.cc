#include <cstdint>
#include <iostream>
#include <string>

#include "glog/logging.h"

int main(int argc, char* argv[]) {
  google::InitGoogleLogging(argv[0]);

  LOG(INFO) << "Test";

  return 0;
}
