#include <bits/stdc++.h>
using namespace std;
const int N = 10010;
int n;
int f[4][N];
int main()
{

    memset(f, 0x3f, sizeof f);
    for (int i = 0; i < N; i++) {
        f[1][i] = i;
    }

    for (int i = 2; i <= 3; i++) {
        f[i][0] = 0;
        for (int j = 1; j < N; j++) {

            // o(k*n*n)
            //  for (int k = 1; k <= j; k++) {
            //      f[i][j] = min(f[i][j], max(f[i - 1][k - 1], f[i][j - k]) + 1);
            //  }


        
            //O(k*n*log(n))
            int l = 1, r = j;
            while (l < r) {
                int mid = (l + r) >> 1;
                if (f[i - 1][mid - 1] >= f[i][j - mid])
                    r = mid;
                else l = mid + 1;
            }
            f[i][j] = max(f[i - 1][l - 1],f[i][j - l]) + 1;
        }
    }
    while (cin >> n) {
        cout << f[3][n] << endl;
    }

    return 0;
}
