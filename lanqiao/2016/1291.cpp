#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int main()
{
    int num[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int cnt = 0;
    do {
        double a = num[0], b = num[1], c = num[2];
        double def = num[3] * 100 + num[4] * 10 + num[5];
        double ghi = num[6] * 100 + num[7] * 10 + num[8];
        double res = a + b / c + def / ghi;
        if (abs(10 - res) < 1e-4) {
            // printf("%d + %d/%d + %d/%d\n", (int)a, (int)b, (int)c, (int)def,
            //        (int)ghi);
            cnt++;
        }
    } while (next_permutation(num, num + 9));
    cout << cnt << endl;
    return 0;
}
