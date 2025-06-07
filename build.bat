@echo off
setlocal

set PARSER_CPP=include\parser.cpp

g++ example.cpp %PARSER_CPP% -o example.exe

./example.exe

endlocal