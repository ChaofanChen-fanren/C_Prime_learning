#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100010, mod = 1e9 + 9;
ll sz[N], d[N];
ll n;
int fact[N], infact[N];
int C(int a, int b)
{
    return (ll)fact[a] * infact[a - b] % mod * infact[b] % mod;
}
int qmi(int a, int b)
{
    ll res = 1;
    while (b) {
        if (b & 1)
            res = res * a % mod;
        a = (ll)a * a % mod;
        b >>= 1;
    }

    return res;
}
void init()
{
    fact[0] = 1;
    infact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = (ll)fact[i - 1] * i % mod;
        infact[i] = (ll)infact[i - 1] * qmi(i, mod - 2) % mod;
    }
}

int dp(int i)
{
    if (sz[i] <= 1)
        return 1;
    int l = 2 * i, r = 2 * i + 1;
    // int fl = dp(l),fr = dp(r);
    // cout<<i<<" "<<l<<" "<<r<<endl;
    // cout<<"---"<<sz[i] - 1<<" "<<sz[l]<<" "<<fl<<" "<<fr<<endl;
    // int res = (ll)C(sz[i] - 1, sz[l]) * fl % mod * fr % mod;
    // cout<<i<<" "<<res<<endl;
    return (ll)C(sz[i] - 1, sz[l]) * dp(l) % mod * dp(r) % mod;
}
int main()
{
    cin >> n;
    for (int i = n; i >= 1; i--) {
        sz[i] = 1;
        int l = 2 * i, r = 2 * i + 1;
        if (l <= n)
            sz[i] += sz[l];
        if (r <= n)
            sz[i] += sz[r];
    }
    // for(int i = 1;i <= n;i++) cout<<sz[i]<<endl;
    init();  // 初始化C(a,b);
    cout << dp(1) << endl;
    return 0;
}
