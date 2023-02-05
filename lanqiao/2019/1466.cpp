#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int a[N];
int n;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);

    // k_1d,k_2d .... k_nd 的最小公倍数
    int d = a[1] - a[0];
    for (int i = 1; i < n; i++) {
        d = __gcd(d, a[i] - a[0]);
    }

    if (d == 0)
        cout << n << endl;
    else
        cout << (a[n - 1] - a[0]) / d + 1 << endl;
    return 0;
}
