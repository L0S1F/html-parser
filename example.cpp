/*
  ||======================================================||
  ||    GitHub: https://github.com/L0S1F/html_parser      ||
  ||    License: MIT                                      ||
  ||    Last Update: 8.06.2025                            ||
  ||======================================================||
*/

#include <iostream>
#include "include/parser.h"

int main() {
    HTMLParser htmlParser("index.html");
    CSSParser cssParser(htmlParser.getStyle());
    std::cout << "Language Page: " << htmlParser.getLanguage() << std::endl;
    std::cout << "Title Page: " << htmlParser.getTitle() << std::endl;
    std::cout << "Style body: " << cssParser.getStyleBody() << std::endl;
    std::cout << "Style #button: " << cssParser.getStyle("#button") << std::endl;

    return 0;
}