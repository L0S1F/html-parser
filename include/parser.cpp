/*
  ||======================================================||
  ||    GitHub: https://github.com/L0S1F/html_parser      ||
  ||    License: MIT                                      ||
  ||    Last Update: 7.06.2025                            ||
  ||======================================================||
*/

#include "parser.h"

std::string Parser::getLanguage() {
    std::regex lang_page("lang=\\\"([a-zA-Z\\-_]+)\\\"");
    std::smatch match; 
    if (std::regex_search(html_content, match, lang_page)) {
        if(match[1].str() == "en" || match[1].str() == "en_US", match[1].str() == "en-US")
            return "English";
        else if(match[1].str() == "uk" || match[1].str() == "uk_UA" || match[1].str() == "uk-UA")
            return "Ukrainian";
        else
            return "Unknown Language: " + match[1].str();
    } else {
        return RED "The page language was not found.\n" RESET_COLOR;
    }
}

Parser::Parser(const char* htmlFileName) {
    htmlFile.open(htmlFileName);
    if(htmlFile.is_open()) {
        std::cout << GRN "HTML-File opened successfully" RESET_COLOR << std::endl;
        std::cout << YEL "Start reading HTML-File" RESET_COLOR << std::endl;
        std::stringstream buffer;
        buffer << htmlFile.rdbuf();
        html_content = buffer.str();
        htmlFile.close();
        std::cout << GRN "HTML-File read successfully" RESET_COLOR << std::endl;
    } else {
        std::cerr << RED "Error open HTML-File!" RESET_COLOR << std::endl;
    }

}

Parser::~Parser() {
    if(htmlFile.is_open()) 
        htmlFile.close();
}