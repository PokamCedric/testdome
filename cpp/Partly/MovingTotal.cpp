/*
Design a data structure that can, efficiently with respect to time used, store and check if the total of any three successively added elements is equal to a given total.

For example, instantiating a MovingTotal object creates an empty container with no existing totals. append({1, 2, 3, 4}) appends elements {1, 2, 3, 4}, which means that there are two existing totals (1 + 2 + 3 = 6 and 2 + 3 + 4 = 9). append({5}) appends element 5 and creates an additional total from {3, 4, 5}. There would now be three totals (1 + 2 + 3 = 6, 2 + 3 + 4 = 9, and 3 + 4 + 5 = 12). At this point contains(6), contains(9), and contains(12) should return true, while contains(7) should return false.
*/

#include<iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>


class MovingTotal
{
public:

    void append(const std::vector<int>& list)
    {
        m_v.insert(m_v.end(), list.begin(), list.end());
        for (int i = 3 - 1; i < m_v.size(); i++)
        {
            int tot = m_v[i] + m_v[i - 1] + m_v[i - 2];
            sum[tot] = tot;
        }
    }

    bool contains(int total)
    {
        return sum[total];
    }
private:
    std::vector<int> m_v;
    std::unordered_map<int, int> sum;

};

#ifndef RunTests
int main()
{
    MovingTotal movingTotal;

    std::vector<int> first;
    first.push_back(1);
    first.push_back(2);
    first.push_back(3);
    first.push_back(4);

    movingTotal.append(first);

    std::cout << movingTotal.contains(6) << std::endl;
    std::cout << movingTotal.contains(9) << std::endl;
    std::cout << movingTotal.contains(12) << std::endl;
    std::cout << movingTotal.contains(7) << std::endl;

    std::vector<int> second;
    second.push_back(5);
    movingTotal.append(second);

    std::cout << movingTotal.contains(6) << std::endl;
    std::cout << movingTotal.contains(9) << std::endl;
    std::cout << movingTotal.contains(12) << std::endl;
    std::cout << movingTotal.contains(7) << std::endl;
}
#endif
