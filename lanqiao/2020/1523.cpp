#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
int pre[N], st[26];
char str[N];
int main()
{
    cin >> (str + 1);
    int n = strlen(str + 1);
    for (int i = 1; i <= n; i++) {
        pre[i] = st[str[i] - 'a'];
        st[str[i] - 'a'] = i;
    }

    long long res = 0;
    for (int i = 1; i <= n; i++) {
        // 字符统计又最左边的字符构成的字符串
        res += (long long)(n + 1 - i) * (i - pre[i]);
    }
    cout << res << endl;
    return 0;
}
