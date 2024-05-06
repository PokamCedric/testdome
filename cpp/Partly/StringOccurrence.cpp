#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <regex>
#include <iterator>

int getLineOccurrences(std::string txt, std::string pat)
{
    int found = txt.find(pat);
    int count = 0;
    while (found != std::string::npos) {
        found = txt.find(pat, found + 1);

        count++;
    }

    return count;
}

int getOccurrenceCount(std::string toSearch, std::istream& stream)
{
    int result = 0;
    while (!stream.eof())
    {
        std::string line;
        std::getline(stream, line);

        result += getLineOccurrences(line, toSearch);
        if (stream.fail())
        {
            //error
            break;
        }
    }

    return result;
}

#ifndef RunTests
int main()
{
    std::stringstream haystack("Hey! How are you?\nI am good, how about you?\nI am good too.");
    std::cout << getOccurrenceCount("good", haystack) << std::endl;
}
#endif