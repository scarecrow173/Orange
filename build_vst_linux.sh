#!/bin/bash
if [ ! -e build]; then mkdir build;fi
pushd build
if [ ! -e linux]; then mkdir linux;fi 
pushd linux

"../../tools/cmake/linux/x86_64/bin/cmake" -DSMTG_ADD_VST3_HOSTING_SAMPLES=FALSE -DSMTG_ADD_VST3_PLUGINS_SAMPLES=FALSE DVSTGUI_TOOLS=FALSE -DSMTG_MYPLUGINS_SRC_PATH=`dirname $0` "../../dependencies/vstsdk"
"../../tools/cmake/linux/x86_64/bin/cmake" --build . --config Debug
"../../tools/cmake/linux/x86_64/bin/cmake" --build . --config Release

popd
popd