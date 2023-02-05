#include <bits/stdc++.h>
#include <vector>
using namespace std;
const int N = 3000010;
vector<int> ed[N];  // ed结尾的区间：存长度为len
int f[N];           // f[i]前1 ~ i区间中最大占多少个数
// f[i] = max(f[i - 1],f[i - len] + len);
// 枚举以i结尾的区间长度
int main()
{
    int n, mx;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int l, r;
        cin >> l >> r;
        ed[r].push_back(r - l + 1);
        mx = max(r, mx);
    }

    for (int i = 1; i <= mx; i++) {
        f[i] = f[i - 1];
        for (int j = 0; j < ed[i].size(); j++) {
            f[i] = max(f[i], f[i - ed[i][j]] + ed[i][j]);
        }
    }

    cout << f[mx] << endl;
    return 0;
}
