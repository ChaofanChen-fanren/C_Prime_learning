#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while (cin >> n) {
        // int res = n, cnt = n;
        // while (cnt >= 3) {
        //     res += cnt / 3;
        //     cnt = cnt % 3 + cnt / 3;
        // }
        // cout << res << endl;
        cout<< n + (n - 1)/2 << endl;
    }
    return 0;
}
