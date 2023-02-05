#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define inf 10000000000
const int N = 35010, INF = 0x3f3f3f3f;
inline long long min(long long x, long long y)
{
    return x < y ? x : y;
}
inline int abs(int x)
{
    return x > 0 ? x : -x;
}
int a[N], b[N];
// f[i] 以b[i]结尾的最长上升子序列
// g[i] 长度为i的最小长度；
int f[N], g[N], len;
long long dp[N];
vector<int> v[N];
long long sum1[N], sum2[N];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i] - i;
    }

    memset(g, 0x3f, sizeof g);
    for (int i = 1; i <= n; i++) {
        int tmp = upper_bound(g, g + len + 1, b[i]) - g;
        // cout << tmp << endl;
        len = max(len, tmp + 1);
        f[i] = tmp + 1;
        g[tmp] = b[i];
        v[tmp + 1].push_back(i);
    }
    cout << n - len << endl;

    v[0].push_back(0);  // b[0]
    b[0] = -INF;
    f[n + 1] = len + 1;  // b[n + 1];
    b[n + 1] = INF;

    // 初始化dp
    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;

    for (int j = 1; j <= n + 1; j++) {                  // 枚举j
        for (int p = 0; p < v[f[j] - 1].size(); p++) {  // 枚举i
            int i = v[f[j] - 1][p];
            if (i > j || b[i] > b[j])
                continue;
            // cout << j << " " << i << endl;

            sum1[i] = sum2[j] = 0;
            for (int q = i + 1; q < j; q++)
                sum1[q] = sum1[q - 1] + abs(b[q] - b[i]);
            for (int q = j - 1; q > i; q--)
                sum2[q] = sum2[q + 1] + abs(b[q] - b[j]);

            long long ans = 1e18;
            for (int k = i; k < j; k++) {
                ans = min(ans, sum1[k] + sum2[k + 1]);
            }
            dp[j] = min(dp[j], dp[i] + ans);
        }
    }
    cout << dp[n + 1] << endl;
    return 0;
}
