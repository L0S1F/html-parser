#!/bin/bash

PARSER_CPP="include/parser.cpp"

g++ example.cpp "$PARSER_CPP" -o example

chmod +x example

./example