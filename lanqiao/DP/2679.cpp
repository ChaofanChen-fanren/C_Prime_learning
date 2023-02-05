#include <bits/stdc++.h>
using namespace std;
const int N = 210, M = 1010, mod = 1000000007;
int f[2][N][N][2];
// f[i][j][k][0/1] A的前i个字符和B前j个字符中用了k段 是否用了当前字符
// f[i][j][k][0] = f[i - 1][j][k][1] + f[i - 1][j][k][0];
// (A[i] == B[j]):
// f[i][j][k][1] = f[i - 1][j - 1][k - 1][1]
//                +f[i - 1][j - 1][k - 1][0]
//                +f[i - 1][j - 1][k][1]
//
char a[M], b[N];
int n, m, t;
int main()
{
    cin >> n >> m >> t;
    cin >> (a + 1) >> (b + 1);

    f[0][0][0][0] = 1;
    // f[1][0][0][0] = 1;//初始化f[i][0][0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k <= t; k++) {
                if (a[i] == b[j]) {
                    int& v = f[i & 1][j][k][1];
                    v = 0;
                    v = (v + f[i - 1 & 1][j - 1][k - 1][1]) % mod;
                    v = (v + f[i - 1 & 1][j - 1][k - 1][0]) % mod;
                    v = (v + f[i - 1 & 1][j - 1][k][1]) % mod;
                    f[i & 1][j][k][0] =
                        (f[i - 1 & 1][j][k][0] + f[i - 1 & 1][j][k][1]) % mod;
                }
                else {
                    f[i & 1][j][k][0] =
                        (f[i - 1 & 1][j][k][0] + f[i - 1 & 1][j][k][1]) % mod;
                    f[i & 1][j][k][1] = 0;
                }
            }
        }
    }

    int res = (f[n & 1][m][t][0] + f[n & 1][m][t][1]) % mod;
    cout << res << endl;

    return 0;
}
