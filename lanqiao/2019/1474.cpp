#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int a[N];
int n, k;
bool check(int s)
{
    int res = 0;
    for (int i = 1; i <= k; i++) {
        int t = s;
        if (res < a[i]) {
            t -= (a[i] - res - 1) * 2;
            // cout<<t<<endl;
            if (t < 0)
                return false;
        }
        res = max(res, a[i] + t / 2);
        // cout<<res<<endl;
    }
    return res >= n;
}
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
        cin >> a[i];

    sort(a + 1, a + k + 1);

    int l = 0, r = 200000;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    cout << l << endl;
    // cout<<check(6)<<endl;
    return 0;
}
