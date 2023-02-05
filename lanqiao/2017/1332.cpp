#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[10] = {0};
    for (int i = 1; i <= 9; i++)
        a[i] = i;
    do {
        if (a[0] == 0 || a[4] == 0 || a[8] == 0)
            continue;

        int b = a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3];
        int c = a[4] * 1000 + a[5] * 100 + a[6] * 10 + a[7];
        int d = a[8] * 10 + a[9];
        if ((b - c) * d == 900) {
            cout << b << " " << c << " " << d << endl;
        }
    } while (next_permutation(a, a + 10));
    // 5012 4987 36
    // 6048 5973 12
    cout << "(6048 - 5973)*12=900";
    return 0;
}
