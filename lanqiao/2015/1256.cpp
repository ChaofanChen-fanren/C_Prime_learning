#include <bits/stdc++.h>
#include <cstring>
using namespace std;
const int N = 7, mod = 1e9 + 7;
int op[] = {0, 4, 5, 6, 1, 2, 3};
int a[N][N], st[N][N];
int n, m;
void mul(int c[], int a[], int b[][N])
{
    int temp[N] = {0};
    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 6; j++) {
            temp[i] = (temp[i] + (long long)a[j] * b[j][i]) % mod;
        }
    }
    memcpy(c, temp, sizeof(temp));
}
void mul(int c[][N], int a[][N], int b[][N])
{
    int temp[N][N] = {0};
    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 6; j++) {
            for (int k = 1; k <= 6; k++) {
                temp[i][j] = (temp[i][j] + (long long)a[i][k] * b[k][j]) % mod;
            }
        }
    }
    memcpy(c, temp, sizeof(temp));
}
int main()
{
    while (cin >> n >> m) {
        memset(st, 0, sizeof st);
        memset(a, 0, sizeof a);
        
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            st[a][b] = st[b][a] = true;
        }

        int f1[N] = {0, 4, 4, 4, 4, 4, 4};
        for (int i = 1; i <= 6; i++) {
            for (int j = 1; j <= 6; j++) {
                if (st[i][op[j]])
                    a[i][j] = 0;
                else
                    a[i][j] = 4;
            }
        }

        n--;
        while (n) {
            if (n & 1)
                mul(f1, f1, a);
            mul(a, a, a);
            n >>= 1;
        }

        int res = 0;
        for (int i = 1; i <= 6; i++) {
            res = (res + f1[i]) % mod;
        }
        cout << res << endl;
    }
    return 0;
}
