#include <bits/stdc++.h>
using namespace std;
set<string> s;
string str;
int main()
{
    string str = "0100110001010001";
    for (int i = 0; i < str.size(); i++) {
        for (int j = i; j < str.size(); j++) {
            s.insert(str.substr(i, j - i + 1));
        }
    }
    cout << s.size() << endl;
    return 0;
}
