#!/bin/bash
mkdir build
pushd build
mkdir mac
pushd mac

"../../tools/cmake/mac/CMake.app/Contents/bin/cmake" "../../dependencies/vstsdk"
"../../tools/cmake/mac/CMake.app/Contents/bin/cmake" --build . --config Debug
"../../tools/cmake/mac/CMake.app/Contents/bin/cmake" --build . --config Release

popd
popd