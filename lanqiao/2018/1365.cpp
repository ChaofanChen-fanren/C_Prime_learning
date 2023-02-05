#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
char g[N][N];
int n, st[N][N];
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
bool dfs(int x, int y)
{
    st[x][y] = true;
    bool flag = false,flag1 = true;
    for (int i = 0; i < 4; i++) {
        int a = x + dx[i], b = y + dy[i];
        if (a < 0 || a >= n || b < 0 || b >= n || st[a][b])
            continue;
        if (g[a][b] == '.' ) {
            flag1 = false;
            continue;
        }
        if (dfs(a, b))
            flag = true;
    }
    return flag || flag1;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> g[i];

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!st[i][j] && g[i][j] == '#') {
                if (!dfs(i, j))
                    ans++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
