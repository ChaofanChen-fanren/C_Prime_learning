#include <bits/stdc++.h>
using namespace std;
const int N = 2010;
int h[N], e[N], ne[N], w[N], idx;
int f[N];
int n;
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
int dp(int u)
{
    if (f[u])
        return f[u];
    f[u] = w[u];
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        f[u] = max(f[u], dp(j) + w[u]);
    }
    return f[u];
}
int main()
{
    memset(h, -1, sizeof h);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> w[i];

    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int x;
            cin >> x;
            if (x)
                add(i, j);  // 有向
        }
    }

    int res = 0, id = -1;
    for (int i = 1; i <= n; i++) {
        int t = dp(i);
        if (res < t) {
            res = t;
            id = i;
        }
    }

    cout << id << " ";
    while (id != -1) {
        for (int i = h[id]; i != -1; i = ne[id]) {
            int j = e[i];
            if (f[j] + w[id] == f[id]) {
                cout << j << " ";
                id = j;
                break;
            }
        }
    }
    cout << endl;

    cout << res << endl;
    return 0;
}
