#include <bits/stdc++.h>
#include <string>
using namespace std;
int main()
{
    string s;
    while (cin >> s) {
        int num = 10;
        while (num >= 10) {
            num = 0;
            for (int i = 0; i < s.size(); i++) {
                num += s[i] - '0';
            }
            //cout << "--" << num << endl;
            s = to_string(num);
        }
        cout << num << endl;
    }
    return 0;
}
