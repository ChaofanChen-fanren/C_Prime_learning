#include <bits/stdc++.h>
using namespace std;
// 19 个点 直接迪杰斯特拉 求单源最短路-.-
int g[20][20];
int dist[20];
bool st[20];
int n = 19;
int dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    for (int i = 0; i < n; i++) {
        int t = -1;
        for (int j = 1; j <= n; j++) {
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        }

        for (int j = 1; j <= n; j++)
            dist[j] = min(dist[j], dist[t] + g[t][j]);

        st[t] = true;
    }
    return dist[19];
}
void add(int a, int b, int c)  // 初始化边
{
    g[a][b] = g[b][a] = c;
}
int main()
{
    memset(g, 0x3f, sizeof g);
    // 根据图中的边初始化
    add(1, 2, 2);
    add(1, 3, 1);
    add(1, 4, 1);
    add(1, 5, 1);
    add(2, 7, 1);
    add(2, 10, 2);
    add(3, 6, 3);
    add(3, 7, 3);
    add(3, 4, 3);
    add(4, 5, 1);
    add(4, 7, 2);
    add(4, 8, 1);
    add(4, 9, 2);
    add(5, 8, 1);
    add(5, 9, 3);
    add(6, 7, 1);
    add(6, 10, 1);
    add(7, 9, 3);
    add(7, 11, 2);
    add(8, 9, 1);
    add(8, 12, 2);
    add(9, 13, 3);
    add(10, 19, 2);
    add(11, 12, 3);
    add(11, 14, 1);
    add(11, 16, 2);
    add(12, 13, 1);
    add(12, 18, 1);
    add(13, 17, 1);
    add(13, 19, 1);
    add(13, 14, 2);
    add(14, 16, 1);
    add(15, 16, 1);
    add(15, 17, 1);
    add(15, 18, 3);
    add(18, 19, 1);
    cout << dijkstra() << endl;
    return 0;
}
