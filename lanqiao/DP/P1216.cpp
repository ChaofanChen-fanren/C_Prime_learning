#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int f[N][N];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> f[i][j];
        }
    }

    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            f[i][j] += max(f[i + 1][j], f[i + 1][j + 1]);
            // cout << f[i][j] << " ";
        }
        // cout << endl;
    }

    cout << f[1][1] << endl;
    return 0;
}
