#include <bits/stdc++.h>
#include <cstdio>
#include <string>
using namespace std;
int cnt[26];
string s;
int main()
{
    while (cin >> s) {
        memset(cnt, 0, sizeof cnt);
        for (int i = 0; i < s.size(); i++) {
            cnt[s[i] - 'a']++;
        }

        int res = -1;
        char c = 'a';

        for (int i = 0; i < 26; i++) {
            // cout<<cnt[i]<<endl;
            if (res < cnt[i]) {
                res = cnt[i];
                c = 'a' + i;
            }
        }
        cout << c << endl;
        cout << res << endl;
    }

    return 0;
}
