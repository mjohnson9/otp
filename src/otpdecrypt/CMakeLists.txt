CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

set(CMAKE_CXX_VISIBILITY_PRESET hidden)

ADD_EXECUTABLE(otpdecrypt otpdecrypt.cc)
TARGET_LINK_LIBRARIES(otpdecrypt
    ${GFLAGS_LIBS_DIRS}/libgflags.a
    otp
)
ADD_DEPENDENCIES(otpdecrypt googleflags)
