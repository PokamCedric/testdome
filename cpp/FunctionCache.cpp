#include <iostream>
#include <unordered_map>
#include <memory>
#include <functional>


// Only for pairs of std::hash-able types for simplicity.
// You can of course template this struct to allow other hash functions
struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1, T2>& p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);

        // Mainly for demonstration purposes, i.e. works but is overly simple
        // In the real world, use sth. like boost.hash_combine
        return h1 ^ h2;
    }
};

class FunctionCache
{
    class Parameters
    {
    public:
        Parameters(int first, int second)
        {
            this->first = first;
            this->second = second;
        }

        int first;
        int second;
    };

public:
    FunctionCache(std::function<int(int, int)> function) : function(function) {}

    int calculate(int first, int second)
    {
        std::pair<int, int> args(first, second);
        auto it = calculations.find(args);
        if (it != calculations.end())
            return it->second;

        int calculation = function(first, second);
        calculations[args] = calculation;
 
        return calculation;
    }

private:
    std::unordered_map<std::pair<int, int>, int, pair_hash> calculations;
    std::function<int(int, int)> function;
};

#ifndef RunTests

int modulo(int a, int b)
{
    std::cout << "Function modulo has been called.\n";
    return a % b;
}

int main()
{
    FunctionCache cache(modulo);

    // Function modulo should be called.
    std::cout << cache.calculate(5, 2) << std::endl;

    // Function modulo should be called.
    std::cout << cache.calculate(7, 4) << std::endl;

    // Function modulo shouldn't be called because we have already made a call with arguments (5, 2)!
    std::cout << cache.calculate(5, 2) << std::endl;
}
#endif