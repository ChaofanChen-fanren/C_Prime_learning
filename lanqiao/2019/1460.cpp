#include <bits/stdc++.h>
using namespace std;
const int N = 110, M = 1 << 20;
int f[M];
int w[N];
int n, m, T;
int main()
{
    cin >> n >> m >> T;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= T; j++) {
            int x;
            cin >> x;
            w[i] |= 1 << (x - 1);
        }
    }

    memset(f, 0x3f, sizeof f);
    f[0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int state = (1 << m) - 1; state >= 0; state--) {
            int end = state | w[i];
            f[end] = min(f[end], f[state] + 1);
        }
    }

    if (f[(1 << m) - 1] == 0x3f3f3f3f)
        cout << "-1" << endl;
    else
        cout << f[(1 << m) - 1] << endl;
    return 0;
}
