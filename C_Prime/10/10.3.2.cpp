#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void elimDups(vector<string>& words)
{
    // sort word
    sort(words.begin(), words.end());
    // unique()
    auto end_unique = unique(words.begin(), words.end());
    // word erase
    words.erase(end_unique, words.end());
}
// for_each()
// capatrue list and find_if
void biggies(vector<string>& words, vector<string>::size_type sz)
{
    elimDups(words);
    stable_sort(
        words.begin(), words.end(),
        [](const string& a, const string& b) { return a.size() < b.size(); });

    // size >= sz
    auto wc = find_if(words.begin(), words.end(),
                      [sz](const string& a) { return a.size() >= sz; });
    auto count = words.end() - wc;
    cout << count << endl;

    // print string
    for_each(wc, words.end(), [](const string& s) { cout << s << " "; });
    cout<<endl;
}
int main()
{
    // lambda expression
    //[captrue](parameter list) -> return type {function body}
    vector<string> words = {"aaa", "bbb", "Ccccc", "ddd"};
    stable_sort(
        words.begin(), words.end(),
        [](const string& a, const string& b) { return a.size() < b.size(); });

    biggies(words, 4);
    return 0;
}
