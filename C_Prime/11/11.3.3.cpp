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
int main()
{
    // earse()

    // c.erase(k)  k = key_value   return : cnt
    // c.erase(p)  p = iterator    return : iterator
    // c.erase(b,e) b - > e earse return : iterator
    map<int, int> imap;
    imap.erase(imap.begin(),imap.end());



    return 0;
}
