#!/bin/bash
mkdir build
pushd build
mkdir linux
pushd linux

"../../tools/cmake/linux/x86_64/bin/cmake" "../../dependencies/vstsdk"
"../../tools/cmake/linux/x86_64/bin/cmake" --build . --config Debug
"../../tools/cmake/linux/x86_64/bin/cmake" --build . --config Release

popd
popd