CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

include(ExternalProject)

ExternalProject_Add(googleflags
    GIT_REPOSITORY "https://github.com/gflags/gflags.git"
    GIT_TAG "v2.2.1"
    PREFIX ${CMAKE_CURRENT_BINARY_DIR}
    INSTALL_COMMAND ""
)

ExternalProject_Get_Property(googleflags BINARY_DIR)
set(GFLAGS_INCLUDE_DIRS ${BINARY_DIR}/include PARENT_SCOPE)
set(GFLAGS_LINK_DIRS ${BINARY_DIR}/lib PARENT_SCOPE)
set(GFLAGS_LIBS_DIRS ${BINARY_DIR}/lib PARENT_SCOPE)
