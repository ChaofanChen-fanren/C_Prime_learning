#include <bits/stdc++.h>
using namespace std;
const int N = 300010, INF = 0x3f3f3f3f;
int f[N][10];  // f[i][j] 时间剩i秒体力剩j个时候走的最长路
// 当前j到10要k秒 k = (10 - j) + 3/4;
// 1.直接走 2.等到有10个能力点直接加速
// f[i][j] = max(f[i - 1][j] + 17,f[i - k - 1][(j + k*4)%10] + 60);
int n, m, s;
int main()
{
    cin >> m >> s >> n;
    int T = m / 10;
    if (s - T * 60 <= 0 && T <= n) {
        cout << "Yes" << endl;
        cout << (s + 59) / 60 << endl;
        return 0;
    }
    else if (s - n * 60 >= 0 && T >= n) {
        cout << "No" << endl;
        cout << n * 60 << endl;
        return 0;
    }

    //
    s -= T * 60;
    m = m % 10;
    n -= T;

    int res = INF;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 10; j++) {
            f[i][j] = f[i - 1][j] + 17;
            int k = ((10 - j) + 3) / 4;
            if (i - k - 1 >= 0)
                f[i][j] = max(f[i][j], f[i - k - 1][(j + k * 4) % 10] + 60);
            if (f[i][j] >= s) {
                if (j > m) {
                    res = min(res, i + (j - m + 3) / 4);
                }
                else {
                    res = min(res, i);
                }
            }
        }
    }

    if (res != INF) {
        cout << "Yes" << endl;
        cout << res + T << endl;
    }
    else {
        int ans = 0;
        // for (int i = 0; i <= m; i++)
        //     ans = max(ans, f[n][i]);
        cout << "No" << endl;
        cout << f[n][m] + T * 60 << endl;
    }

    return 0;
}
