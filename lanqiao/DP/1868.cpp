#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
const int N = 150010;
struct Node
{
    int l, r;
    int len;
    bool operator<(const struct Node& t) const
    {
        return r < t.r;
    }
} a[N];
int n, f[N];
// f[i]  前i个区间中选能得到的最大数量
// f[i] = max(f[i - 1],f[j] + 区间长度)
// j前j个区间最结尾都不超过a[i].tail;(排序+二分)
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].l >> a[i].r;
        a[i].len = a[i].r - a[i].l + 1;
    }
    sort(a + 1, a + n + 1);

    for (int i = 1; i <= n; i++) {
        int l = 0, r = i - 1;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (a[mid].r < a[i].l)
                l = mid;
            else
                r = mid - 1;
        }
        f[i] = max(f[i - 1], f[r] + a[i].len);
        // cout << "--" << i << " " << r << endl;
        // cout << f[i] << endl;
    }

    cout << f[n] << endl;
    return 0;
}
