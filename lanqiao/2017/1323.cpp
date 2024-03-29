#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int a[N], b[N], n, m;
bool check(int x)
{
    int res = 0;
    for (int i = 0; i < n; i++) {
        res += a[i]/x*(b[i]/x);
    }
    return res >= m;
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];

    int l = 1, r = 1e5;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }

    cout << l << endl;
    return 0;
}
