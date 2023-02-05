#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
const int N = 1010;
int n, m;
vector<int> a[N];
int f[4][N];
int main()
{
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        a[x % m].push_back(x);
    }

    memset(f, -0x3f, sizeof f);
    f[0][0] = 0;

    for (int i = 0; i < m; i++) {
        sort(a[i].begin(), a[i].end());
        reverse(a[i].begin(), a[i].end());

        for (int u = 0; u < 3 && u < a[i].size(); u++) {
            int w = a[i][u];
            for (int j = 3; j >= 1; j--) {
                for (int k = 0; k < m; k++) {
                    f[j][k] = max(f[j][k], f[j - 1][(k - w % m + m) % m] + w);
                }
            }
        }
    }

    cout << f[3][0] << endl;
    return 0;
}
