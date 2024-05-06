/* ----Book Sale
Write a method that, efficiently with respect to time used, finds the n-th lowest selling book
in the list. Each element of the sales array represents a single sale of a book with that book's id.
The n-th lowest selling book is the book that has more sales than n-1 books. Assume that book sales counts are unique.

For example, nthLowestSelling({ 5, 4, 3, 2, 1, 5, 4, 3, 2, 5, 4, 3, 5, 4, 5 }, 2) should return 2.
In the array, the book with the id 1 was sold once, id 2 twice, id 3 three times, id 4 four times,
and id 5 five times, making the book with the id 1 the lowest selling book in the array and id 2 the second lowest selling book.
*/


#include <vector>
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_map>


int nthLowestSelling(const std::vector<int>& sales, int n)
{
    //std::multiset<int> st(sales.begin(), sales.end());
    std::unordered_map<int, int> count;
    for (int i : sales) {
        ++count[i];
    }

    std::set<int> my_set(sales.begin(), sales.end());
    std::vector<int> my_vec(my_set.begin(), my_set.end());
    std::sort(my_vec.begin(), my_vec.end(),
        [&](const int& i1, const int& i2) {
            return count[i1] < count[i2];
        }
    );

    return my_vec.at(n - 1);
}

#ifndef RunTests
int main()
{
    std::vector<int> input;
    input.push_back(5);
    input.push_back(4);
    input.push_back(3);
    input.push_back(2);
    input.push_back(1);
    input.push_back(5);
    input.push_back(4);
    input.push_back(3);
    input.push_back(2);
    input.push_back(5);
    input.push_back(4);
    input.push_back(3);
    input.push_back(5);
    input.push_back(4);
    input.push_back(5);

    int x = nthLowestSelling(input, 2);
    std::cout << x;
}
#endif

This snippet does what you want, by combining an std::set, a lambda and std::multiset::count:

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

int main() {
    std::multiset<int> st;
    st.insert(12);
    st.insert(12);
    st.insert(12);
    st.insert(145);
    st.insert(145);
    st.insert(1);
    st.insert(2);

    std::set<int> my_set(st.begin(), st.end());
    std::vector<int> my_vec(my_set.begin(), my_set.end());
    std::sort(my_vec.begin(), my_vec.end(), 
      [&](const int &i1, const int &i2) {
          return st.count(i1) < st.count(i2);
      }
    );

    for(auto i : my_vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

You might want to reverse the vector. This outputs:

1 2 145 12

Edit: Taking into account you also need the item count, this will do it:

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

int main() {
    typedef std::vector<std::pair<int, int>> MyVector;
    std::multiset<int> st;
    st.insert(12);
    st.insert(12);
    st.insert(12);
    st.insert(145);
    st.insert(145);
    st.insert(1);
    st.insert(2);

    std::set<int> my_set(st.begin(), st.end());
    MyVector my_vec;
    my_vec.reserve(my_set.size());

    for(auto i : my_set) 
        my_vec.emplace_back(i, st.count(i));

    std::sort(my_vec.begin(), my_vec.end(), 
      [&](const MyVector::value_type &i1, const MyVector::value_type &i2) {
          return i1.second < i2.second;
      }
    );

    for(const auto &i : my_vec)
        std::cout << i.first << " -> " << i.second << std::endl;
}

Which outputs:

1 -> 1
2 -> 1
145 -> 2
12 -> 3

