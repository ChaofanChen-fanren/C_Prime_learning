#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 200010;
int n, m;
int a[N];
int main()
{
    cin >> n >> m;
    int len = n + m + 1;
    for (int i = 1; i <= len; i++) {
        cin >> a[i];
    }

    sort(a + 1, a + 1 + len);

    ll res = 0;
    if (!m) {
        for (int i = 1; i <= len; i++)
            res += a[i];
    }
    else {
        res += a[len], res -= a[1];
        for (int i = 2; i < len; i++)
            res += abs(a[i]);
    }

    cout << res << endl;

    return 0;
}
