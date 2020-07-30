#!/bin/bash

PluginSrcPath="`pwd`/Orange"

if [ ! -e build ]; then mkdir build;fi
pushd build
if [ ! -e mac ]; then mkdir mac;fi
pushd mac

"../../tools/cmake/mac/CMake.app/Contents/bin/cmake" -DCMAKE_BUILD_TYPE=Debug -DSMTG_ADD_VST3_HOSTING_SAMPLES=FALSE -DSMTG_ADD_VST3_PLUGINS_SAMPLES=FALSE DVSTGUI_TOOLS=FALSE -DSMTG_MYPLUGINS_SRC_PATH=$PluginSrcPath "../../dependencies/vstsdk"
"../../tools/cmake/mac/CMake.app/Contents/bin/cmake" --build . --config Debug

"../../tools/cmake/mac/CMake.app/Contents/bin/cmake" -DCMAKE_BUILD_TYPE=Release -DSMTG_ADD_VST3_HOSTING_SAMPLES=FALSE -DSMTG_ADD_VST3_PLUGINS_SAMPLES=FALSE DVSTGUI_TOOLS=FALSE -DSMTG_MYPLUGINS_SRC_PATH=$PluginSrcPath "../../dependencies/vstsdk"
"../../tools/cmake/mac/CMake.app/Contents/bin/cmake" --build . --config Release

popd
popd
