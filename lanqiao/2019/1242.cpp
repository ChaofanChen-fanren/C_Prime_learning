#include <bits/stdc++.h>
using namespace std;
const int N = 2000010;
int st[N];
int n;
int lowbit(int x)
{
    return x & (-x);
}
void add(int x, int c)
{
    for (int i = x; i < N; i += lowbit(i))
        st[i] += c;
}
int query(int x)
{
    int res = 0;
    for (int i = x; i; i -= lowbit(i))
        res += st[i];
    return res;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        // 找到第一个大于等于x的数 二分
        int l = x, r = 2e6;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (query(mid) - query(x - 1) < (mid - x + 1))
                r = mid;
            else
                l = mid + 1;
        }
        add(l, 1);
        cout << l << " ";
    }
    cout << endl;
    return 0;
}
