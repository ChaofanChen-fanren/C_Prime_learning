#include <bits/stdc++.h>
using namespace std;
unordered_map<char, int> m;
int main()
{
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
        m[s[i]]++;

    int maxn = m[s[0]], minn = m[s[0]];
    for (auto [k, v] : m) {
        if (v > maxn)
            maxn = v;
        if (v < minn)
            minn = v;
    }
    cout << maxn - minn << endl;
    return 0;
}
