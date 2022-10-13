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
    // key_type mapped_type value_type
    set<string>::value_type v1;  // v1:string
    set<string>::key_type v2;    // v2:string
    map<string, int>::value_type v3;  // v3:pair<string,int>
    map<string, int>::key_type v4;    // v4:string
    map<string, int>::mapped_type v5;  // v5: int

    // iterator   map->pair 
    map<string, int> word_count = {{"a", 1}};
    auto map_it = word_count.begin();
    cout << map_it->first << " " << map_it->second << endl;
    // map_it->first = "hhh"; // error map_it->first is const

    set<int> iset = {0, 1, 2, 3, 4, 5, 6};
    set<int>::iterator set_it = iset.begin();
    while (set_it != iset.end()) {
        cout << *set_it << " ";
        set_it++;
    }

    

    return 0;
}
