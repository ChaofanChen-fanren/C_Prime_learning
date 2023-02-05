#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int f[4][N], n;
int main()
{
    n = 1000;
    memset(f, 0x3f, sizeof f);
    for (int i = 0; i <= n; i++)
        f[1][i] = i;

    for (int i = 2; i <= 3; i++) {
        f[i][0] = 0;
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= j; k++) {
                f[i][j] =
                    min(f[i][j], max(f[i - 1][k - 1], f[i][j - k]) + 1);
            }
        }
    }

    cout << f[3][n] << endl;
    return 0;
}
