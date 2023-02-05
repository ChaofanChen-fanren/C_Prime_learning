#include <bits/stdc++.h>
#include <cstring>
using namespace std;
const int N = 3000;
char g[N][N];
int dx[] = {0, 1, 1, -1}, dy[] = {1, 0, 1, -1};
int res = 0;
int n, m;
void dfs(int x, int y, int k,string s)
{
    s += g[x][y];
    if (s.size() == 4) {
        if (s == "2020") {
            //cout << x << " " << y << endl;
            res++;
        }
        return;
    }
    int a = x + dx[k], b = y + dy[k];
    if (a < 0 || a >= n || b < 0 || b >= m)
        return;
    dfs(a,b,k,s);
}
int main()
{
    n = 300;
    for (int i = 0; i < n; i++)
        cin >> g[i];
    m = strlen(g[0]);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 3; k++) {
                dfs(i,j,k,"");
            }
        }
    }
    cout<<res<<endl;
    return 0;
}
