#include <bits/stdc++.h>
#include <vector>
using namespace std;
const int N = 10010;
int n;
struct Segment
{
    int x, y1, y2;
    int k;
    bool operator<(const Segment& t) const
    {
        return x < t.x;
    }
} seg[N * 2];
struct Node
{
    int l, r;
    int cnt, len;
} tr[N * 4];
void build(int u, int l, int r)
{
    tr[u] = {l, r};
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
}
void pushup(int u)
{
    if (tr[u].cnt > 0)
        tr[u].len = tr[u].r - tr[u].l + 1;
    else if (tr[u].l == tr[u].r)
        tr[u].len = 0;
    else
        tr[u].len = tr[u << 1].len + tr[u << 1 | 1].len;
}
void modify(int u, int l, int r, int v)
{
    if (l <= tr[u].l && tr[u].r <= r) {
        tr[u].cnt += v;
        pushup(u);
        return;
    }

    int mid = (tr[u].l + tr[u].r) >> 1;
    if (l <= mid)
        modify(u << 1, l, r, v);
    if (r > mid)
        modify(u << 1 | 1, l, r, v);
    pushup(u);
}
int main()
{
    int n;
    scanf("%d", &n);
    int m = 0;
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 > x2)
            swap(x1, x2);
        if (y1 > y2)
            swap(y1, y2);

        seg[m++] = {x1, y1, y2, 1};
        seg[m++] = {x2, y1, y2, -1};
    }

    sort(seg, seg + m);

    build(1, 0, 10000);

    long long res = 0;
    for (int i = 0; i < m; i++) {
        if (i > 0) {
            res += (long long)tr[1].len * (seg[i].x - seg[i - 1].x);
        }
        modify(1, seg[i].y1, seg[i].y2, seg[i].k);
    }

    cout << res << endl;
    return 0;
}
