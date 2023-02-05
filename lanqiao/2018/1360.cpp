#include <bits/stdc++.h>
using namespace std;
int main()
{
    int temp = 0, ans = 0;
    for (int i = 1901; i <= 2000; i++) {
        if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0) {
            ans += 366;
        }
        else {
            ans += 365;
        }
    }

    ans = ans / 7;
    cout << ans;
    return 0;
}
