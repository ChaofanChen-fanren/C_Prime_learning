#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
const int N = 100010;
unordered_map<int, int> pos;
int a[N];
int n;
struct Node
{
    int l, r;
    int sum;
} tr[4*N];
void pushup(int u)
{
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}
void build(int u, int l, int r)
{
    if (l == r) {
        tr[u] = {l, r, 0};
        return;
    }
    int mid = (l + r) >> 1;
    tr[u] = {l, r};
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}
void modify(int u, int pos, int x)
{
    if (tr[u].l == tr[u].r) {
        tr[u].sum += x;
        return;
    }
    int mid = (tr[u].l + tr[u].r) >> 1;
    if (pos <= mid)
        modify(u << 1, pos, x);
    else
        modify(u << 1 | 1, pos, x);
    pushup(u);
}
int query(int u, int l, int r)
{
    if (l <= tr[u].l && tr[u].r <= r) {
        return tr[u].sum;
    }
    int mid = (tr[u].l + tr[u].r) >> 1;
    int res = 0;
    if (l <= mid)
        res += query(u << 1, l, r);
    if (mid < r)
        res += query(u << 1 | 1, l, r);
    return res;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);
    for (int i = 1; i <= n; i++) {
        if (pos.count(a[i]) == 0) {
            pos[a[i]] = i;
            cout << -a[i] << " ";
            modify(1, i, 1);
        }
        else {
            int pre = pos[a[i]];
            cout << query(1, pre + 1, i - 1) << " ";
            modify(1, pre, -1);
            pos[a[i]] = i;
            modify(1, i, 1);
        }
    }
    cout << endl;
    return 0;
}
