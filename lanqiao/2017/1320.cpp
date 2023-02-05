#include <bits/stdc++.h>
using namespace std;
int vis[7][7];
int ans;
int dx[] = {-1,1,0,0},dy[] = {0,0,-1,1};
void dfs(int x, int y)
{
    if (x == 0 || x == 6 || y == 0 || y == 6) {
        ans++;
        return;
    }

    for (int i = 0; i < 4; i++) {
        int a = x + dx[i], b = y + dy[i];
        if(vis[a][b]) continue;
        vis[a][b] = true;
        vis[6 - a][6 - b] = true;
        dfs(a, b);
        vis[a][b] = false;
        vis[6 - a][6 - b] = false;
    }
}
int main()
{
    vis[3][3] = true;
    dfs(3, 3);
    cout << ans / 4 << endl;
    return 0;
}
