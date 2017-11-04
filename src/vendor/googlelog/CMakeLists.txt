CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

include(ExternalProject)

ExternalProject_Add(googlelog
    GIT_REPOSITORY "https://github.com/google/glog"
    GIT_TAG "v0.3.5"
    PREFIX ${CMAKE_CURRENT_BINARY_DIR}
    INSTALL_COMMAND ""
)

ExternalProject_Get_Property(googlelog SOURCE_DIR)
ExternalProject_Get_Property(googlelog BINARY_DIR)

set(GLOG_INCLUDE_DIRS ${SOURCE_DIR}/src ${BINARY_DIR} PARENT_SCOPE)
set(GLOG_LINK_DIRS ${BINARY_DIR} PARENT_SCOPE)
