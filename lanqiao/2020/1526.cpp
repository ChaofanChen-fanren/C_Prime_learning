#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int f[N][N];
int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> f[i][j];
        }
    }

    // k = n - 1;左右走的总步数总数
    // 左边和右边不能相差1，只能在 f[n][k/2 + 1] 或 f[n][k/2](k为奇数)
    // f[n][k/2](k为偶数)出发

    if (n & 1) {
        for (int i = 1; i <= n; i++) {
            if (i != n / 2 + 1)
                f[n][i] = -0x3f3f3f3f;
        }
    }
    else {
        for (int i = 1; i <= n; i++) {
            if (i != n / 2 && i != n / 2 + 1)
                f[n][i] = -0x3f3f3f3f;
        }
    }

    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            f[i][j] += max(f[i + 1][j], f[i + 1][j + 1]);
        }
    }

    cout << f[1][1] << endl;

    return 0;
}
