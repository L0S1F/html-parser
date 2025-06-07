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
    setlocale(LC_ALL, "uk_UA");
    HTMLParser parser("index.html");
    parser.getHTMLData();
    std::cout << "\nНатиснiть будь-яку клавiшу щоб закрити програму\n";
    system("pause>nul");
    return 0;
}