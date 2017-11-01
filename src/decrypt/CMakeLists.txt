CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

ADD_EXECUTABLE(otpdecrypt decrypt.cc)
TARGET_LINK_LIBRARIES(otpdecrypt
    glog
    otp
)
