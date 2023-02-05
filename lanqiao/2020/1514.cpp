#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 1200000;

    int res = 1;
    for (int i = 2; i <= n / i; i++) {
        if (n % i == 0) {
            int s = 0;
            while (n % i == 0) {
                n /= i;
                s++;
            }
            res *= (s + 1);
        }
    }
    if (n > 1)
        res *= 2;

    cout << res << endl;
    return 0;
}
