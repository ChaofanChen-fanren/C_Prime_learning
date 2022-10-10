#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
void elimDups(vector<string>& words)
{
    // sort word
    sort(words.begin(), words.end());
    //unique()
    auto end_unique = unique(words.begin(), words.end());
    // word erase
    words.erase(end_unique, words.end());
}
int main()
{
    vector<string> words = {"a", "b", "a", "c"};
    elimDups(words);
    for (auto str : words) {
        cout << str << " ";
    }
    cout << endl;
    return 0;
}
