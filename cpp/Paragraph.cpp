#include <iostream>
#include <string>
#include <regex>
#include <iterator>


std::string changeWordFormat(const std::string paragraph)
{
    std::smatch m;
    std::regex r("([[:digit:]]{3})-([[:digit:]]{2})-([[:digit:]]{4})");

    bool match = std::regex_search(paragraph, m, r);
    if (match) {
        std::string newValue = m.format("$1") + "/" + m.format("$3") + "/" + m.format("$2");
        return std::regex_replace(paragraph, r, newValue);
    }

    return "NOT OK";
}

std::string changeFormat( const std::string paragraph)
{
    std::regex words_regex("[[:digit:]]{3}-[[:digit:]]{2}-[[:digit:]]{4}");
    auto words_begin = std::sregex_iterator(paragraph.begin(), paragraph.end(), words_regex);
    auto words_end = std::sregex_iterator();

    std::string str = paragraph;

    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        std::smatch match = *i;
        const std::string match_str = changeWordFormat(match.str());
        str.replace(str.find(match.str()), match_str.length(), match_str);
    }

    return str;
}

#ifndef RunTests
int main()
{
    std::cout << changeFormat("Please quote your policy number: 112-39-8552. and my 023-12-1990");
}
#endif

