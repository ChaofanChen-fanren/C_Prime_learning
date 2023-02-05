#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int num[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
bool check(int g[][4])
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            for (int x = i - 1; x <= i + 1; x++) {
                for (int y = j - 1; y <= j + 1; y++) {
                    if (x < 0 || x >= 3 || y < 0 || y >= 4)
                        continue;
                    if (x == i && y == j)
                        continue;
                    if (abs(g[i][j] - g[x][y]) == 1)
                        return false;
                }
            }
        }
    }
    return true;
}
int main()
{
    int res = 0;
    do {
        int g[3][4] = {20,     num[0], num[1], num[2], num[3], num[4],
                       num[5], num[6], num[7], num[8], num[9], 20};
        if (check(g))
            res++;
    } while (next_permutation(num, num + 10));
    cout << res << endl;
    return 0;
}
