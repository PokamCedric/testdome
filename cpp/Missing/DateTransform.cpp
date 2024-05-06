#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <regex>


inline int isFormatMatching(const std::regex r, std::string word)
{
    return std::regex_search(word, r);
}

const char* getFormat(std::string date) {
    std::pair<std::string, std::string>  mm = { "(0[0-9]|1[012])", "MM" };
    std::pair<std::string, std::string>  dd = { "(0[1-9]|[12][0-9]|3[01])", "DD" };
    std::pair<std::string, std::string>  yyyy = { "(^d{4})", "YYYY" };

    std::vector< std::string> reg{   
        std::string{yyyy.first + "/" + dd.first + "/" + mm.first},
        std::string{dd.first + "/" + mm.first + "/" + yyyy.first},
        std::string{dd.first + "-" + mm.first + "-" + yyyy.first},
        std::string{yyyy.first + dd.first + mm.first}
    };

    std::vector< std::string> days{
        std::string{yyyy.second + "/" + dd.second + "/" + mm.second},
        std::string{dd.second + "/" + mm.second + "/" + yyyy.second},
        std::string{dd.second + "-" + mm.second + "-" + yyyy.second},
        std::string{yyyy.second + dd.second + mm.second}
    };
    for (int i = 0; i < reg.size(); i++) {
        if (isFormatMatching(std::regex (reg[i]), date))
            return days[i].c_str();
        }

    return nullptr;
}


std::string getDate(std::string date) {
    std::string newDate;
    struct tm tm;
    const char* format = getFormat(date);
    strptime(date.c_str(), format, &tm);

    char date2[10];
    strftime(date2, sizeof(date2), format, &tm);
    int size = 7;
    for (int i = 0; i < size; i++) {
        newDate.push_back(date2[i]);
    }

    return newDate;
}


std::vector<std::string> transformDateFormat(const std::vector<std::string>& dates)
{
    std::vector<std::string> newDates;
    for (auto date : dates) {
        newDates.push_back(getDate(date));
    }

    return newDates;
}


#ifndef RunTests
int main()
{
    std::vector<std::string> dates = { "2010/02/20", "19/12/2016", "11-18-2012", "20130720" };
    std::vector<std::string> reformattedDates = transformDateFormat(dates);
    for (auto const& reformattedDate : reformattedDates)
    {
        std::cout << reformattedDate << std::endl;
    }
}
#endif