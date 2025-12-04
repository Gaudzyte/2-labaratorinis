rmdir /s /q build
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build .
V2_0.exe
pause
