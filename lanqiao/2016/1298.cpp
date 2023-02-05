#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int f[N][2][2];  // f[n][i][j](i,j只能取0,1)还有n个球要取我手
                 // 中有i个球对手有j个球
int a[3];
// mine是我,your是对方s
int dp(int n, int mine, int your)
{
    if (f[n][mine][your] != -1)
        return f[n][mine][your];
    if (n < a[1]) {
        if (mine % 2 == your % 2) {  // 奇偶相等 平局
            return f[n][mine][your] = 0;
        }
        else if (mine % 2 != your % 2 && mine % 2) {  // 奇偶相等
            return f[n][mine][your] = 1;
        }
        else {
            return f[n][mine][your] = 2;
        }
    }

    int flag = 0;  // 是否存在平局
    for (int i = 1; i <= 3; i++) {
        if (a[i] > n)
            break;  // 排序的a[i],后面的也不符合
        int ans = dp(n - a[i], your, (mine + a[i]) % 2);
        if (ans == 2) {  // 有一种对手一定会输
            return f[n][mine][your] = 1;
        }
        else if (ans == 0) {
            flag = true;
        }
    }

    // 只有平均或者失败了
    if (flag)
        return f[n][mine][your] = 0;  // 如果有平均就返回平局
    return f[n][mine][your] = 2;
}
int main()
{
    while (cin >> a[1]) {
        for (int i = 2; i <= 3; i++)
            cin >> a[i];
        sort(a + 1, a + 1 + 3);

        memset(f, -1, sizeof f);
        int n;
        for (int i = 0; i < 5; i++) {
            cin >> n;
            int res = dp(n, 0, 0);
            if (res == 0)
                cout << "0 ";
            else if (res == 1)
                cout << "+ ";
            else
                cout << "- ";
        }
        cout << endl;
    }
}
