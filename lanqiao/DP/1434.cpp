#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
const int N = 110;
int g[N][N], f[N][N];
int n, m;
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};

int dp(int x, int y)
{
    if (f[x][y])
        return f[x][y];
    for (int i = 0; i < 4; i++) {
        int a = x + dx[i], b = y + dy[i];
        if (a <= 0 || a > n || b <= 0 || b > m)
            continue;
        if (g[a][b] >= g[x][y])
            continue;
        f[x][y] = max(dp(a, b), f[x][y]);
    }
    f[x][y]++;

    return f[x][y];
}
int main()
{
    // 记忆化搜索
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            res = max(res, dp(i, j));
        }
    }
    cout << res << endl;

    return 0;
}
