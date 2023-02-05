#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int a[N][N];
int f[N][N][N];  // f[i][j][k] 向右边走了多少次
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> a[i][j];
        }
    }

    memset(f, 0, sizeof f);
    for (int i = 1; i <= n; i++)
        f[n][i][0] = a[n][i];
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            for (int k = 0; k <= n - i; k++) {
                f[i][j][k] = a[i][j] + f[i + 1][j][k];
                if (k >= 1)
                    f[i][j][k] =
                        max(f[i][j][k], a[i][j] + f[i + 1][j + 1][k - 1]);
            }
        }
    }

    n--;
    if (n & 1)
        cout << max(f[1][1][n / 2 + 1], f[1][1][n / 2]) << endl;
    else
        cout << f[1][1][n / 2] << endl;

    return 0;
}
