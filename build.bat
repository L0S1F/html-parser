@echo off
setlocal

g++ example.cpp include\parser.cpp -o example.exe

./example.exe

endlocal