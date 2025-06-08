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

class Parser {
    public:
        Parser(const char* htmlFileName);
        ~Parser();
        std::string getLanguage();
        std::string getTitle();
    private:
        std::ifstream htmlFile;
        std::string html_content;
    
};