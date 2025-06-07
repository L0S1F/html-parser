/*
  ||======================================================||
  ||    GitHub: https://github.com/L0S1F/html_parser      ||
  ||    License: MIT                                      ||
  ||    Last Update: 7.06.2025                            ||
  ||======================================================||
*/

#include <iostream>
#include "include/parser.h"

int main() {
    Parser htmlParser("index.html");
    std::cout << htmlParser.getLanguage() << std::endl;
    return 0;
}