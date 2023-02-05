#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int n, m, T;
typedef pair<int, int> PII;
int pre[N], cnt[N], st[N];
PII p[N];
int main()
{
    cin >> n >> m >> T;

    for (int i = 0; i < m; i++) {
        cin >> p[i].first >> p[i].second;
    }
    sort(p, p + m);
    for (int i = 0; i < m; i++) {
        int t = p[i].first, id = p[i].second;
        if (t > pre[id])
            cnt[id] -= (t - 1) - pre[id];  // 防止两个连续的t
        if (cnt[id] < 0)
            cnt[id] = 0;

        if (cnt[id] <= 3)
            st[id] = false;
        cnt[id] += 2;  // 优先级更新
        if (cnt[id] > 5)
            st[id] = true;
        pre[id] = t;  // 上一次更新的时间
    }

    // 全部更新到时间T
    int res = 0;
    for (int i = 1; i <= n; i++) {
        cnt[i] -= T - pre[i];
        if (cnt[i] <= 3)
            st[i] = false;
    }

    for (int i = 1; i <= n; i++)
        res += st[i];
    cout << res << endl;
    return 0;
}
