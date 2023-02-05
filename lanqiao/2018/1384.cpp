#include <bits/stdc++.h>
#include <string>
#include <utility>
#include <vector>
using namespace std;
typedef pair<int, int> PII;
const int N = 110;
char g[N][N], st[N][N];
int n;
int ans;
int dx[] = {0, 0, 1, -1, 1, 1, -1, -1}, dy[] = {1, -1, 0, 0, 1, -1, 1, -1};
// 题目方向不变则 id记录方向
void dfs(int x, int y, string s, int id)
{
    if (x < 0 || y >= n || x < 0 || y >= n)
        return;
    if (s.size() == 7) {
        if (s == "LANQIAO") {
            ans++;
        }
        return;
    }
    int i = x + dx[id], j = y + dy[id];
    dfs(i, j, s + g[i][j], id);
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> g[i];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (g[i][j] == 'L') {  // 方向是不变的
                for (int id = 0; id < 8; id++)
                    dfs(i, j, string(1, g[i][j]), id);
            }
        }
    }

    cout << ans << endl;  // 41
    return 0;
}
