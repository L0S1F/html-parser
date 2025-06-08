/*
  ||======================================================||
  ||    GitHub: https://github.com/L0S1F/html_parser      ||
  ||    License: MIT                                      ||
  ||    Last Update: 8.06.2025                            ||
  ||======================================================||
*/

#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <regex>
#include "colored_text.h"


class HTMLParser {
  public:
    HTMLParser(const char* htmlFileName);
    ~HTMLParser();
    std::string getLanguage();
    std::string getTitle();
    std::string getStyle();

  private:
    std::ifstream htmlFile;
    std::string html_content;
    
};

class CSSParser {
  public:
    CSSParser(std::string cssContent);
    ~CSSParser();
    std::string getStyleBody();
    std::string getStyle(const std::string& element);
  private:
    std::string css_content;
};