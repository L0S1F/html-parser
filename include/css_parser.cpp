/*
  ||======================================================||
  ||    GitHub: https://github.com/L0S1F/html_parser      ||
  ||    License: MIT                                      ||
  ||    Last Update: 8.06.2025                            ||
  ||======================================================||
*/

#include "parser.h"

std::string CSSParser::getStyleBody() {
    std::regex style_regex(R"(body\s*\{\s*((?:.|\n)*?)\s*\})", std::regex::icase);
    std::smatch match; 
    if (std::regex_search(css_content, match, style_regex)) {
        return match[1].str();
    } else {
        return RED "The page style body was not found.\n" RESET_COLOR;
    }
}

std::string CSSParser::getStyle(const std::string& element) {
    std::string pattern = element + R"(\s*\{\s*((?:.|\n)*?)\s*\})";
    std::regex style_regex(pattern, std::regex::icase);
    std::smatch match; 

    if (std::regex_search(css_content, match, style_regex)) {
        return match[1].str();
    } else {
        return RED "The page element was not found.\n" RESET_COLOR;
    }
}


CSSParser::CSSParser(std::string cssContent) {
    css_content = cssContent;
}

CSSParser::~CSSParser() {
    
}