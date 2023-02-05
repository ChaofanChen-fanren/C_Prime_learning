#include <bits/stdc++.h>
using namespace std;
const int N = 10;
int g[N][N];
int path[N], cnt, st[N];
void dfs(int u)
{
    st[u] = true;
    for (int i = 0; i < cnt; i++) {
        if (!st[i] && g[path[u]][path[i]]) {
            dfs(i);
        }
    }
}
int check()
{
    for (int i = 0; i < cnt; i++) {
        if (!st[i])
            return false;
    }
    return true;
}
int main()
{
    g[0][1] = g[0][5] = true;
    g[1][0] = g[1][6] = g[1][2] = true;
    g[2][1] = g[2][6] = g[2][3] = true;
    g[3][2] = g[3][4] = true;
    g[4][3] = g[4][5] = g[4][6] = true;
    g[5][0] = g[5][4] = g[5][6] = true;
    g[6][1] = g[6][2] = g[6][4] = g[6][5] = true;

    int res = 0;
    for (int state = 1; state < 1 << 7; state++) {
        cnt = 0;
        for (int j = 0; j < 7; j++) {
            if (state >> j & 1) {
                path[cnt++] = j;
            }
        }
        memset(st, 0, sizeof st);
        dfs(0);
        res += check();
    }
    cout << res << endl;
    return 0;
}
