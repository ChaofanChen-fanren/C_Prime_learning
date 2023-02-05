#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1010;
int f[N][N];
int main()
{
    string s;
    while (cin >> s) {
        int n = s.size();
        memset(f, 0x3f, sizeof f);
        for (int len = 0; len <= n; len++) {
            for (int l = 0; l + len - 1 < n; l++) {
                int r = l + len - 1;
                if (l == r || len == 0)
                    f[l][r] = len;
                else {
                    f[l][r] = max(f[l + 1][r], f[l][r - 1]);
                    if (s[l] == s[r])
                        f[l][r] = max(f[l][r], f[l + 1][r - 1] + 2);
                }
            }
        }
        cout << n - f[0][n - 1] << endl;
    }

    return 0;
}
