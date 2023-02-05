#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int s[N], cnt[N];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] = (s[i - 1] + s[i]) % m;
    }

    long long res = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] % m == 0)
            res++;
        res += cnt[s[i]];
        cnt[s[i]]++;
    }

    cout << res << endl;
    return 0;
}
