#!/bin/bash

clear

g++ example.cpp include/html_parser.cpp include/css_parser.cpp -o example

chmod +x example

./example