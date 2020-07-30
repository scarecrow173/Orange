if not exist build mkdir build
pushd build
if not exist x86 mkdir x86
pushd x86

"../../tools/cmake/windows/x64/bin/cmake.exe" -DSMTG_ADD_VST3_HOSTING_SAMPLES=FALSE -DSMTG_ADD_VST3_PLUGINS_SAMPLES=FALSE -DVSTGUI_TOOLS=FALSE -DSMTG_MYPLUGINS_SRC_PATH="%~dp0Orange" -G "Visual Studio 15 2017" -A Win32 "../../dependencies/vstsdk"
"../../tools/cmake/windows/x64/bin/cmake.exe" --build . --config Debug
"../../tools/cmake/windows/x64/bin/cmake.exe" --build . --config Release

popd
popd