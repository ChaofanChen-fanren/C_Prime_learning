#include <algorithm>
#include <cstddef>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
struct Sales_data
{
    string isbn;
    int count;
};
size_t hasher(const Sales_data& sd)
{
    return hash<string>()(sd.isbn);
}
bool eqOp(const Sales_data &lhs,const Sales_data &rhs)
{
    return lhs.isbn == rhs.isbn;
}
int main()
{
    // unoredred_map and unordered_set


    // hash<key_type>
    using SD_multiset =
        unordered_multiset<Sales_data, decltype(hasher)*, decltype(eqOp)*>;
    SD_multiset bookstore(42, hasher, eqOp);

    return 0;
}
