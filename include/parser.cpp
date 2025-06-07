/*
  ||======================================================||
  ||    GitHub: https://github.com/losif22/html_parser    ||
  ||    License: MIT                                      ||
  ||    Last Update: 7.06.2025                            ||
  ||======================================================||
*/

#include "parser.h"

std::string HTMLTagParser::parseTitle(const std::string& html_content) {
    std::smatch match;
    if (std::regex_search(html_content, match, title_regex)) {
        return match[1];
    }
    return "";
}

std::string HTMLTagParser::parseBody(const std::string& html_content) {
    std::smatch match;
    if (std::regex_search(html_content, match, body_regex)) {
        return match[1];
    }
    return ""; 
}

std::string getHTMLVersion(const std::string& html_content) {
    std::regex html5_regex("<!DOCTYPE\\s+html>", std::regex::icase);
    std::regex html4_regex("<!DOCTYPE\\s+HTML\\s+PUBLIC\\s+\"-//W3C//DTD\\s+HTML\\s+4\\.01//EN\"", std::regex::icase);
    std::regex xhtml_regex("<!DOCTYPE\\s+html\\s+PUBLIC\\s+\"-//W3C//DTD\\s+XHTML\\s+1\\.0\\s+Strict//EN\"", std::regex::icase);

    if (std::regex_search(html_content, html5_regex)) {
        return "HTML5";
    }
    else if (std::regex_search(html_content, html4_regex)) {
        return "HTML 4.01";
    }
    else if (std::regex_search(html_content, xhtml_regex)) {
        return "XHTML 1.0";
    }
    else {
        return "Unknown HTML Version";
    }
}

std::string HTMLTagParser::parseLang(const std::string& html_content) {
    std::smatch match;
    if (std::regex_search(html_content, match, lang_regex)) {
        return match[1];
    }
    return "";
}

std::string HTMLTagParser::parseEncoding(const std::string& html_content) {
    std::smatch match;
    if (std::regex_search(html_content, match, encoding_regex)) {
        return match[1];
    }
    return "";
}

std::vector<std::pair<std::string, std::string>> HTMLTagParser::parseButtons(const std::string& html_content) {
    std::vector<std::pair<std::string, std::string>> buttons;
    std::smatch match;
    auto button_begin = std::sregex_iterator(html_content.begin(), html_content.end(), button_regex);
    auto button_end = std::sregex_iterator();

    for (auto it = button_begin; it != button_end; ++it) {
        std::string button_class = (*it)[1];  // class
        std::string button_text = (*it)[2];   // текст на кнопці
        buttons.push_back({ button_class, button_text });
    }
    return buttons;
}

HTMLParser::HTMLParser(const char* file_name) {
    html_file.open(file_name);
    if (!html_file) {
        std::cout << "Помилка при відкритті файлу: " << file_name << "\n";
        exit(0);
    }

    std::stringstream buffer{};
    buffer << html_file.rdbuf();
    html_content = buffer.str();
}

HTMLParser::~HTMLParser() {
    if (html_file.is_open()) {
        html_file.close();
    }
}

void HTMLParser::getHTMLData() {
    std::string version = getHTMLVersion(html_content);
    std::string title = html_tags.parseTitle(html_content);
    std::string body = html_tags.parseBody(html_content);
    std::string lang = html_tags.parseLang(html_content);
    std::string encoding = html_tags.parseEncoding(html_content);
    std::vector<std::pair<std::string, std::string>> buttons = html_tags.parseButtons(html_content);

    std::cout << "Версiя HTML: " << version << "\n";
    std::cout << "Мова сторiнки: " << lang << "\n";
    std::cout << "Кодування сторiнки: " << encoding << "\n";
    std::cout << "Назва сторiнки: " << title << "\n";
    std::cout << "Body код: \n(" << body << ");\n";

    std::cout << "Кнопки на сторiнцi:\n";
    for (const auto& button : buttons) {
        std::cout << "Клас: " << button.first << ", Текст: " << button.second << "\n";
    }

} 
