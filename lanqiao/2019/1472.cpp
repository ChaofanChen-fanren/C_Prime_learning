#include <bits/stdc++.h>
using namespace std;
// 顺时针旋转90度
const int N = 110;
int a[N][N], b[N][N];
int n, m;
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    // 每一列每一列的输出
    for (int i = 1; i <= m; i++) {
        for (int j = n; j >= 1; j--) {
            cout << a[j][i] << " ";
        }
        cout << endl;
    }

    return 0;
}
