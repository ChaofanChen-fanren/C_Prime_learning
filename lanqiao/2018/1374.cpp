#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100010, mod = 1e9 + 9;
int n, k;
ll a[N];
int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);

    ll res = 1;
    int l = 0, r = n - 1, sign = 1;
    if (k % 2) {
        res = a[r--];
        k--;
        if (res < 0)
            sign = -1;  // 全是负数
    }

    // 成对选
    while (k) {
        ll lsum = a[l] * a[l + 1], rsum = a[r] * a[r + 1];
        if (lsum * sign > rsum * sign) {
            res = res * (lsum % mod) % mod;
            l += 2;
        }
        else {
            res = res * (rsum % mod) % mod;
            r -= 2;
        }
        k -= 2;
    }

    cout << sign * res << endl;

    return 0;
}
