#include <bits/stdc++.h>
using namespace std;
const int N = 12;
char g[N][N],st[N][N];
bool dfs(int x, int y)
{
    if (x < 0 || x >= 10 || y < 0 || y >= 10)
        return true;
    if(st[x][y]) return false;
    st[x][y] = true;
    if (g[x][y] == 'U')
        return dfs(x - 1, y);
    else if (g[x][y] == 'D')
        return dfs(x + 1, y);
    else if (g[x][y] == 'L')
        return dfs(x, y - 1);
    return dfs(x, y + 1);
}
int main()
{
    int cnt = 0;
    for (int i = 0; i < 10; i++) {
        cin >> g[i];
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            memset(st,0,sizeof st);
            if (dfs(i, j))
                cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
