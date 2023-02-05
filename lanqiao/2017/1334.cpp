#include <bits/stdc++.h>
using namespace std;
const int N = 10;
int g[N][N];
int cnt, st[N];
int m;
int backup[N][N], res[N][N];
void check(int a[])
{
    for (int i = 0, k = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (g[i][j])
                backup[i][j] = g[i][j];
            else
                backup[i][j] = a[k++];
        }
    }

    int s = backup[0][0] + backup[0][1] + backup[0][2];
    if (s != 15)
        return;
    s = backup[1][0] + backup[1][1] + backup[1][2];
    if (s != 15)
        return;
    s = backup[2][0] + backup[2][1] + backup[2][2];
    if (s != 15)
        return;

    s = backup[0][0] + backup[1][0] + backup[2][0];
    if (s != 15)
        return;
    s = backup[0][1] + backup[1][1] + backup[2][1];
    if (s != 15)
        return;
    s = backup[0][2] + backup[1][2] + backup[2][2];
    if (s != 15)
        return;

    s = backup[0][0] + backup[1][1] + backup[2][2];
    if (s != 15)
        return;

    s = backup[0][2] + backup[1][1] + backup[2][0];
    if (s != 15)
        return;

    cnt++;
    if (cnt == 1) {
        for (int i = 0, k = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                res[i][j] = backup[i][j];
            }
        }
    }
    return;
}
int main()
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> g[i][j];
            if (g[i][j])
                st[g[i][j]] = true;
        }
    }

    int num[N];
    for (int i = 1; i <= 9; i++) {
        if (!st[i])
            num[m++] = i;
    }

    // for(int i = 0;i < m;i++) cout<<num[i]<<endl;
    do {
        check(num);
        if (cnt >= 2) {
            cout << "Too Many" << endl;
            return 0;
        }
    } while (next_permutation(num, num + m));

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
