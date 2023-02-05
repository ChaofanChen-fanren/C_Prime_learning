#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 100010, M = N * 2;
int h[N], ne[M], e[M], idx;
int w[N];
long long f[N];
int n;
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
void dfs(int u, int fa)
{
    f[u] = w[u];
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (j != fa) {
            dfs(j, u);
            f[u] += max((long long)0, f[j]);
        }
    }
}
int main()
{
    cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }
    for (int i = 1; i <= n; i++) {
        if (!f[i]) {
            dfs(i, -1);
        }
    }
    long long res = 0;
    for (int i = 1; i <= n; i++) {
        res = max(res, f[i]);
    }
    cout << res << endl;
    return 0;
}
