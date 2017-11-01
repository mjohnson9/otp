#!/bin/bash

export CC="clang"
export CXX="clang++"

exec cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE=Debug -Hsrc -Bbuild -G "Xcode"
