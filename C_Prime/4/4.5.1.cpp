#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string s1 = "a string", *p = &s1;
    auto n = s1.size();

    n = (*p).size(); // * priority lower than .
    n = p->size();

    vector<string> v = {"", "ccc", "ddd", "fff",""};
    auto iter = v.begin();
    cout << *iter << endl;
    // cout << (*iter)++ << endl;
    cout << iter->empty() << endl;
    cout << iter++->empty() << endl;
    cout << *++iter << endl;
    cout << iter++->empty() << endl;

    return 0;
}
