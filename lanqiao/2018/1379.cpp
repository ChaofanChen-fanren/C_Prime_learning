#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 100010;
int a[N], b[N], st[N], res, n;
// 一条线(包含有圆)：如果一个点在圆内，这个结点被经过两次的,
// 第一次的数字与第二次的数字之差为圆的数值 b[]数组的体现
void dfs(int u, int step)
{
    if (st[u]) {
        // 构成环路
        res = max(res, step - b[u]);
        return;
    }
    b[u] = step;
    st[u] = true;
    dfs(a[u], step + 1);
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++) {
        if (!st[i])
            dfs(i, 1);
    }

    cout << res << endl;
    return 0;
}
