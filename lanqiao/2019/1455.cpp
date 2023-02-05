#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef pair<int, int> PII;
const int N = 60;
char g[N][N];
int st[N][N];
map<PII, int> pre;
queue<PII> q;
int dx[] = {1, 0, 0, -1}, dy[] = {0, -1, 1, 0};
int n = 30, m = 50;
char str[] = {'D', 'L', 'R', 'U'};
string bfs(int sx, int sy)
{
    q.push({sx, sy});
    st[sx][sy] = true;

    while (q.size()) {
        auto t = q.front();
        q.pop();

        int x = t.first, y = t.second;
        for (int i = 0; i < 4; i++) {
            int a = x + dx[i], b = y + dy[i];
            if (a < 0 || a >= n || b < 0 || b >= m)
                continue;
            if (st[a][b] || g[a][b] == '1')
                continue;
            st[a][b] = true;
            pre[{a, b}] = i;
            q.push({a, b});
        }
    }

    string res = "";
    int x = n - 1, y = m - 1;
    while (x != sx || y != sy) {
        int id = pre[{x, y}];
        res += str[id];
        x -= dx[id], y -= dy[id];
    }

    reverse(res.begin(), res.end());
    return res;
}
int main()
{
    for (int i = 0; i < n; i++)
        cin >> g[i];

    cout << bfs(0, 0) << endl;

    // cout<<"DDDDRRURRRRRRDRRRRDDDLDDRDDDDDDDDDDDDRDDRRRURRUURRDDDDRDRRRRRRDRRURRDDDRRRRUURUUUUUUULULLUUUURRRRUULLLUUUULLUUULUURRURRURURRRDDRRRRRDDRRDDLLLDDRRDDRDDLDDDLLDDLLLDLDDDLDDRRRRRRRRRDDDDDDRR"<<endl;
    return 0;
}
