#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
    while (cin >> n) {
        long long res = 0;
        for (int i = 1; i <= n; i++) {
            long long num = i;
            while (num != 1) {
                if (num % 2) {
                    num = num * 3 + 1;
                }
                else
                    num = num / 2;
                res = max(res, num);
            }
        }
        cout << res << endl;
    }
    return 0;
}
