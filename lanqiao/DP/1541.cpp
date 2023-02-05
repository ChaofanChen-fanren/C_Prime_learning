#include <bits/stdc++.h>
#include <cmath>
using namespace std;
const int N = 45;
int cnt[5];
int f[N][N][N], w[N * N];
int n, m;

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    for (int i = 0; i <= cnt[1]; i++)
        for (int j = 0; j <= cnt[2]; j++)
            for (int a = 0; a <= cnt[3]; a++)
                for (int b = 0; b <= cnt[4]; b++) {
                    int pos = i * 1 + j * 2 + a * 3 + b * 4 + 1;
                    if (j != 0)
                        f[j][a][b] = max(f[j - 1][a][b], f[j][a][b]);
                    if (a != 0)
                        f[j][a][b] = max(f[j][a - 1][b], f[j][a][b]);
                    if (b != 0)
                        f[j][a][b] = max(f[j][a][b - 1], f[j][a][b]);
                    f[j][a][b] += w[pos];
                }
    cout << f[cnt[2]][cnt[3]][cnt[4]];
    return 0;
}
