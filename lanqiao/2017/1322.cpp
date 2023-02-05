#include <bits/stdc++.h>
using namespace std;
const int N = 10010;
int f[N], a[110];
int main()
{
    int n;
    cin >> n;
    int d = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        d = __gcd(d, a[i]);
    }
    if (d != 1) {
        cout << "INF" << endl;
        return 0;
    }

    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = a[i]; j < N; j++) {
            f[j] |= f[j - a[i]];
        }
    }

    int res = 0;
    for (int i = N - 1; i > 0; i--) {
        if (!f[i]) {
            res++;
        }
    }
    cout << res << endl;
    return 0;
}
