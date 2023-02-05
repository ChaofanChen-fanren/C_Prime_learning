#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll phi(int n)
{
    ll res = n;
    for (ll i = 2; i <= n / i; i++) {
        if (n % i == 0) {
            res = res / i * (i - 1);
            while (n % i == 0)
                n /= i;
        }
    }
    if (n > 1)
        res = res / n * (n - 1);
    return res;
}

inline ll mul(ll x, ll y, ll mod)
{
    return (x * y - (ll)((long double)x / mod * y) * mod + mod) % mod;
}

ll qmi(ll a, ll b, ll mod)
{
    ll res = 1;
    while (b) {
        if (b & 1)
            res = mul(res, a, mod);
        a = mul(a, a, mod);
        b >>= 1;
    }
    return res;
}
int main()
{
    // X = C^e mod n
    ll n = 1001733993063167141;
    ll d = 212353;
    ll C = 20190324;

    ll p, q, e, k;

    for (ll i = 2; i <= n; i++) {
        if (n % i == 0) {
            p = i, q = n / i;
            break;
        }
    }  // 找到p和q
    cout << p << " " << q << endl;
    
    k = (p - 1) * (q - 1);
    e = qmi(d, phi(k) - 1, k);

    cout << e << endl;
    
    ll X = qmi(C, e, n);
    cout << X << endl;

    // n=1001733993063167141
    // p=891234941, q=1123984201
    // k = (p - 1) * (q - 1) = 1001733991047948000 phi(k) = 267048288597043200
    // e = d ^ (phi(k) - 1) = 823816093931522017(mod k)d* e = 1(mod k)
    // X =C ^ e(mod n) = 579706994112328949

    return 0;
}
