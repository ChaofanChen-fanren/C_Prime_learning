#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool isShorter(const string& s1, const string& s2)
{
    return s1.size() > s2.size();
}
int main()
{
    // stable_sort()
    vector<string> words = {"aaa", "bbb", "Ccccc", "ddd"};
    sort(words.begin(),words.end());
    stable_sort(words.begin(), words.end(),
                isShorter);  // euqal length: dictionary order

    for (auto str : words) {
        cout << str << " ";
    }
    cout << endl;
    return 0;
}
