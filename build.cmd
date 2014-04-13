@echo off 

echo .
pushd src
call Make
popd
echo.
start /b huey32.exe

