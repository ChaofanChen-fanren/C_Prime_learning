#include <bits/stdc++.h>
using namespace std;
const int N = 35;
double a[N][N];
int main()
{
    int n = 29;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            char c;
            cin >> c;
            if (isdigit(c))
                a[i][j] = c - '0';
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            a[i + 1][j] += a[i][j] / 2.0;
            a[i + 1][j + 1] += a[i][j] / 2.0;
        }
    }
    double minnum = 400, maxnum = 0;
    for (int i = 1; i <= n + 1; i++) {
        minnum = min(minnum, a[30][i]);
        maxnum = max(maxnum, a[30][i]);
    }
    cout << minnum << " " << maxnum << endl;
    long long res = 2086458231 * maxnum / minnum ;
    cout << res << endl;
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= i; j++) {
    //         printf("%06.4lf ", a[i][j]);
    //     }
    //     cout << endl;
    // }
    // 36668144240
    return 0;
}
