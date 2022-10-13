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
    // [key_value]
    map<string, int> word_count;
    word_count["a"] = 1;
    cout << word_count["a"] << endl;
    cout << word_count.at("a") << endl;


    // find()
    if(word_count.find("b") == word_count.end())
        cout << "b not find" << endl;

    // count()
    cout << word_count.count("a") << endl;
    multiset<int> miset = {1, 2, 3, 3, 3, 3, 3};
    cout << miset.count(3) << endl;

    // lower_bound and upper_bound
    for (auto beg = miset.lower_bound(3), end = miset.upper_bound(3);
         beg != end; beg++) {
        cout << *beg << " ";
    }
    cout << endl;
    // equal_range()
    for (auto pos = miset.equal_range(3); pos.first != pos.second;
         pos.first++) {
        cout << *pos.first << " ";
    }
    cout << endl;
    

    return 0;
}
