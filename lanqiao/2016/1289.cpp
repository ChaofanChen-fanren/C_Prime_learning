#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
const int N = 110;
long long a[N], b[N], x[N], cnt;
long long gcd_sub(long long a, long long b)
{
    if (a < b)
        swap(a, b);
    if (b == 1)
        return a;
    return gcd_sub(b, a / b);
}
int main()
{
    int n;
    while (cin >> n) {
        cnt = 0;
        for (int i = 0; i < n; i++)
            cin >> x[i];
        sort(x, x + n);
        // for(int i = 0;i < n;i++){
        //     cout<<x[i]<<" ";
        // }
        // cout<<endl;
        for (int i = 1; i < n; i++) {
            if (x[i] != x[i - 1]) {
                long long d = __gcd(x[i], x[0]);
                a[cnt] = x[i] / d;
                b[cnt++] = x[0] / d;
            }
        }

        // 指数的最大公约数
        long long up = a[0], down = b[0];
        for (int i = 1; i < cnt; i++) {
            up = gcd_sub(up, a[i]);
            down = gcd_sub(down, b[i]);
        }
        cout << up << "/" << down << endl;
    }
    return 0;
}
