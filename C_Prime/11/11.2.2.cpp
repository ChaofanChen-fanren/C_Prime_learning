#include <algorithm>
#include <cstddef>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
struct Sales_data
{
    string isbn;
    int count;
};
bool compareIsbn(const Sales_data& lhs, const Sales_data& rhs)
{
    return lhs.isbn < rhs.isbn;
}
int main()
{
    // key Compare function
    // compareIsbn and &compareIsbn equal
    multiset<Sales_data, decltype(compareIsbn)*> bookstore(compareIsbn);

    return 0;
}
