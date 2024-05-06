/*
The stoiExcept function wraps the std::stoi function. If the std::stoi function is passed a string that cannot 
be converted to an integer it throws either an invalid_argument exception or an out_of_range exception.

Alter the stoiExcept function so that if std::stoi throws an out_of_range exception, then stoiExcept returns 0.

For example, stoiExcept("100000000000000") should return 0.
*/

#include <string>
#include <iostream>
#include <limits>
#include <algorithm>

bool is_number(const std::string& s)
{
    return !s.empty() && std::find_if(s.begin(), 
        s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}

int stoiExcept(const std::string& str)
{
    if( is_number(str) ){
        
        try {
            return  std::stoi(str);
        }
        catch (const std::out_of_range& e) {
            return  0;
        }
    
        
    }else{
        throw std::invalid_argument("Invalid");
    }
}
