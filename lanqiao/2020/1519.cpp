#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int pre[N], ne[N];
int st[26];
char str[N];
int main()
{
    cin >> str;
    int n = strlen(str);

    // 统计当前字符前一个出现的位置
    memset(st, -1, sizeof st);
    for (int i = 0; i < n; i++) {
        pre[i] = st[str[i] - 'a'];
        // cout<<pre[i]<<" ";
        st[str[i] - 'a'] = i;
    }
    // cout<<endl;

    // 统计当前字符后一个出现的位置
    for (int i = 0; i < 26; i++)
        st[i] = n;

    for (int i = n - 1; i >= 0; i--) {
        ne[i] = st[str[i] - 'a'];
        // cout<<ne[i]<<" ";
        st[str[i] - 'a'] = i;
    }
    // cout<<endl;

    long long res = 0;
    for (int i = 0; i < n; i++) {
        int l = i - pre[i], r = ne[i] - i;
        res += (long long)l * r;
    }

    cout << res << endl;
    return 0;
}
