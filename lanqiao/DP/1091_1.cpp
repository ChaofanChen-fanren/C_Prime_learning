#include <bits/stdc++.h>
#include <pthread.h>
using namespace std;
const int N = 3e5 + 10;
struct Node
{
    int m;     // 当前m的数量
    int mlen;  // 只闪烁的长度
    int f;     // 闪烁和跑步的最优距离
} T[N];
int main()
{
    int n, m, s;
    cin >> m >> s >> n;

    T[0].m = m;

    for (int i = 1; i <= n; i++) {
        if (T[i - 1].m >= 10) {
            T[i].m = T[i - 1].m - 10;
            T[i].mlen = T[i - 1].mlen + 60;
        }
        else {
            T[i].mlen = T[i - 1].mlen;
            T[i].m = T[i - 1].m + 4;
        }
        T[i].f = max(T[i].mlen, T[i - 1].f + 17);
        if (T[i].f >= s) {
            cout << "Yes" << endl;
            cout << i << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    cout << T[n].f << endl;
    return 0;
}
