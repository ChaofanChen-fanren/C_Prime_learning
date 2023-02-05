#include <bits/stdc++.h>
using namespace std;
bool check(int num)
{
    while (num) {
        int res = 0;
        while (num) {
            res += (num % 10) * (num % 10);
            num /= 10;
        }
        cout << res << endl;
        if (res == 1)
            return false;
        num = res;
    }
    return false;
}
int main()
{
    // cout << 145 << endl;
    check(5);
    // for (int i = 1; i <= 10000; i++) {
    //     if (!check(i))
    //         cout << i << endl;
    // }
}
