#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    // ll x, y;
    // cin >> x >> y;
    // if (abs(x) <= y) {
    //     ll n = y;
    //     cout << (2 * n) * (2 * n - 1) + x + n << endl;
    // }
    // else if (abs(y) <= x) {
    //     ll n = x;
    //     cout << (2 * n) * (2 * n) + n - y << endl;
    // }
    // else if (abs(x) <= abs(y) + 1 && y < 0) {
    //     ll n = abs(y);
    //     cout << (2 * n) * (2 * n + 1) + n - x << endl;
    // }
    // else {
    //     ll n = abs(x);
    //     cout << (2 * n - 1) * (2 * n - 1) + y - (-n + 1) << endl;
    // }
    // return 0;

    ll x, y;
    cin >> x >> y;
    int k = max(abs(x), abs(y));
    if (x >= y)
        cout << 4 * k * k + abs(x - k) + abs(y - k) << endl;
    else
        cout << 4 * k * k - abs(x - k) - abs(y - k) << endl;
    return 0;
}
