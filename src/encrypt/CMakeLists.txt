CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

set(CMAKE_CXX_VISIBILITY_PRESET hidden)

ADD_EXECUTABLE(otpencrypt encrypt.cc)
TARGET_LINK_LIBRARIES(otpencrypt
    ${GFLAGS_LIBS_DIRS}/libgflags.a
    otp
)
ADD_DEPENDENCIES(otpencrypt googleflags)
