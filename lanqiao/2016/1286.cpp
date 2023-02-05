#include <bits/stdc++.h>
using namespace std;
int g[3][4],st[3][4];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
void dfs(int a, int b)
{
    st[a][b] = true;
    for (int i = 0; i < 4; i++) {
        int x = a + dx[i], y = b + dy[i];
        if (x < 0 || x >= 3 || y < 0 || y >= 4)
            continue;
        if (!st[x][y] && g[x][y]) {
            dfs(x,y);
        }
    }
}
bool check()
{
    // 赋值
    // dfs判断连通性
    int cnt = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            if (!st[i][j] && g[i][j]) {
                dfs(i, j);
                cnt++;
            }
        }
    }
    
    return cnt == 1;
}
int main()
{
    int num[12] = {0};
    for (int i = 0; i < 5; i++)
        num[i] = 1;
    int res = 0,cnt = 0;
    do {
        memset(g, 0, sizeof g);
        memset(st,0,sizeof st);
        for (int i = 0; i < 12; i++) {
            if (num[i]) {
                // 选择i了
                int x = i / 4, y = i % 4;
                g[x][y] = true;
            }
        }
        if (check()) {
            res++;
        }
    } while (prev_permutation(num, num + 12));
    cout << res << endl;
    return 0;
}
