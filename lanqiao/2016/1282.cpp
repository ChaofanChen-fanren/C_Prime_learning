#include <bits/stdc++.h>
using namespace std;
int main()
{
    int res = 0;
    for (int i = 1; i <= 99; i++) {
        if (i + 27 == (i % 10 * 10 + i / 10)) {
            // cout << i << " " << i + 27 << endl;
            res++;
        }
    }
    cout << res << endl;
    return 0;
}
