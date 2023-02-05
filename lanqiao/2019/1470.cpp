#include <bits/stdc++.h>
using namespace std;
int main()
{
    int ans = 0;
    int a = 2019, b = 324;
    while (a != 0 && b != 0) {
        int len = b;  // 等于较小着
        ans += (a / len) * (b / len);
        // cout << a / len << ":" << b << "X" << b << endl;
        b = a % len;
        a = len;
    }
    cout << ans << endl;
    return 0;
}
