#include <bits/stdc++.h>
using namespace std;
int main()
{
    int mod = 10000;
    int res = 0;
    int a = 1, b = 1, c = 1;

    int n = 20190324 - 3;
    while (n--) {
        int temp = (a + b + c) % mod;
        a = b;
        b = c;
        c = temp;
    }

    cout << c << endl;
    return 0;
}
