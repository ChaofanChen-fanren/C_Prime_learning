#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int num[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
bool check(int g[][4])
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j <= i; j++) {
            if (g[i + 1][j] < g[i][j] || g[i + 1][j + 1] < g[i][j])
                return false;
        }
    }
    return true;
}
int main()
{
    int res = 0;
    do {
        int g[4][4] = {
            num[0], 0,      0,      0, num[1], num[2], 0,      0,
            num[3], num[4], num[5], 0, num[6], num[7], num[8], num[9],
        };

        if (check(g))
            res++;
    } while (next_permutation(num, num + 10));
    cout << res << endl;
    return 0;
}
