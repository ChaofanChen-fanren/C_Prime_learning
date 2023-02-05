#include <bits/stdc++.h>
using namespace std;
int main()
{
    int res = 0;
    for (int i = 1; i <= 2020; i++) {
        int n = i;
        while (n) {
            if (n % 10 == 2)
                res++;
            n /= 10;
        }
    }
    cout << res << endl;
    return 0;
}
