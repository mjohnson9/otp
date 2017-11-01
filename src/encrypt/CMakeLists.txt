CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

ADD_EXECUTABLE(otpencrypt encrypt.cc)
TARGET_LINK_LIBRARIES(otpencrypt
	glog
    otp
)
