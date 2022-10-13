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
    // set insert()
    vector<int> ivec = {2, 4, 6, 8, 2, 4, 6, 8};
    set<int> iset;
    iset.insert(ivec.begin(), ivec.end());
    iset.insert({1, 2, 3, 4});
    for (const auto& val : iset) {
        cout << val << " ";
    }
    cout << endl;

    // map insert()
    map<string, int> word_count;
    word_count.insert({"a", 1});
    word_count.insert(make_pair("b", 2));
    word_count.insert(pair<string, int>("c", 3));
    word_count.insert(map<string, int>::value_type("d", 4));
    auto map_it = word_count.begin();
    while (map_it != word_count.end()) {
        cout << map_it->first << " " << map_it->second << " ";
        map_it++;
    }
    cout << endl;


    // insert return type
    // set : void
    // map : pair<iterator,bool>
    // multimap and multiset : iterator

    


    
    return 0;
}
