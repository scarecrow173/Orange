mkdir build
pushd build
mkdir x64
pushd x64

"../../tools/cmake/windows/x64/bin/cmake.exe" -G "Visual Studio 15 2017" -A x64 "../../dependencies/vstsdk"
"../../tools/cmake/windows/x64/bin/cmake.exe" --build . --config Debug
"../../tools/cmake/windows/x64/bin/cmake.exe" --build . --config Release

popd
popd