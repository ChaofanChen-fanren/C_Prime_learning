#include <cstddef>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;
int main()
{

    // map and set
    map<string, size_t> word_count;
    set<string> exclude = {"The", "But", "And", "Or", "An"};
    string word;
    while (cin >> word) {
        if (exclude.find(word) == exclude.end())
            ++word_count[word];
    }
    for (const auto& w : word_count) {
        cout << w.first << " occurs " << w.second;
        cout << (w.second > 1 ? "times" : "time") << endl;
    }    

    return 0;
}
