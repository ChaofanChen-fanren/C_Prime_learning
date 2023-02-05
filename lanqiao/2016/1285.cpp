#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int num[14];
int st[14], path[14];
void slove1()
{
    long long res = 0;
    do {
        int flag = (num[1] + num[2] == num[3]);
        flag &= (num[4] - num[5] == num[6]);
        flag &= (num[7] * num[8] == num[9]);
        flag &= (num[10] == num[11] * num[12]);
        if (flag) {
            for (int i = 1; i <= 12; i++) {
                cout << num[i] << " ";
            }
            cout << endl;
            res++;
        }
    } while (next_permutation(num + 1, num + 1 + 13));
    cout << res << endl;
}
int f(int u, int a, int b)
{
    int op = u / 2;
    if (op == 0)
        return a + b;
    if (op == 1)
        return a - b;
    if (op == 2)
        return a * b;
    return a * b;
}
// u为偶数时候会用到前一个数
int dfs(int u, int pre)
{
    if (u == 8) {
        // for (int i = 0; i < 8; i++) {
        //     cout<<path[i]<<" ";
        // }
        // cout<<endl;
        return 1;
    }
    int res = 0;
    if (u % 2) {
        for (int i = 1; i <= 13; i++) {
            int t = f(u, pre, i);
            if (t < 1 || t > 13)
                continue;
            if (!st[i] && !st[t] && t != i) {
                // path[u] = i;
                st[i] = true, st[t] = true;
                res += dfs(u + 1, i);
                st[i] = false, st[t] = false;
            }
        }
    }
    else {
        for (int i = 1; i <= 13; i++) {
            if (!st[i]) {
                // path[u] = i;
                st[i] = true;
                res += dfs(u + 1, i);
                st[i] = false;
            }
        }
    }
    return res;
}
int main()
{
    for (int i = 1; i <= 13; i++)
        num[i] = i;
    // 13选12时间太长了
    // 13选8 dfs
    cout << dfs(0, -1) << endl;
    // slove1(); //大约一分钟 64
    return 0;
}
