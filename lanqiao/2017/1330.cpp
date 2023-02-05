#include <bits/stdc++.h>
#include <string>
using namespace std;
int main()
{
    string s;
    int res = 0;
    while (cin >> s) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '#' || s[i] == 'T' || s[i] == 'H')
                res++;
            if (s[i] == '@')
                res += 2;
        }
    }
    cout << res << endl;
    //190
    return 0;
}
