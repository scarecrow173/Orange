#!/bin/bash
mkdir build
pushd build
mkdir mac
pushd mac

"../../tools/cmake/mac/cmake" "../../dependencies/vstsdk"
"../../tools/cmake/mac/cmake" --build . --config Debug
"../../tools/cmake/mac/cmake" --build . --config Release

popd
popd