#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int f[N];
int a[N], q[N], res, cnt;
int main()
{
    int n = 0;
    while (cin >> a[n])
        n++;

    for (int i = 0; i < n; i++) {
        int pos = upper_bound(f, f + res, a[i], greater<int>()) -
                  f;  // 返回第一个小于a的地址
        if (pos == res)
            f[res++] = a[i];
        else
            f[pos] = a[i];
    }
    cout << res << endl;

    for (int i = 0; i < n; i++)
        q[i] = 5e4;

    for (int i = 0; i < n; i++) {
        int l = 0, r = cnt;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (q[mid] >= a[i])
                r = mid;
            else
                l = mid + 1;
        }
        q[r] = a[i];
        cnt = max(cnt, r + 1);
    }
    cout << cnt << endl;
    return 0;
}
