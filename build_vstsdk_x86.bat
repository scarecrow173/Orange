mkdir build
pushd build
mkdir x86
pushd x86

"../../tools/cmake/windows/x86/bin/cmake.exe" -G "Visual Studio 15 2017" -A Win32 "../../dependencies/vstsdk"
"../../tools/cmake/windows/x86/bin/cmake.exe" --build . --config Debug
"../../tools/cmake/windows/x86/bin/cmake.exe" --build . --config Release

popd
popd