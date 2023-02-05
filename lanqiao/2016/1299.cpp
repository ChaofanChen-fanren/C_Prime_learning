#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
const int N = 100010;
int tr[N];
int a[N];
unordered_map<int, int> mp;
int query(int x)
{
    int res = 0;
    for (int i = x; i; i -= (i & -i))
        res += tr[i];
    return res;
}
void add(int x, int c)
{
    for(int i = x;i < N;i += (i & -i)) tr[i] += c;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++) {
        if (mp[a[i]] != 0) {
            add(mp[a[i]], -1);
            add(i, 1);
            cout << query(i - 1) - query(mp[a[i]])<<" ";
            mp[a[i]] = i;
        }
        else {
            mp[a[i]] = i;
            add(i, 1);
            cout<<-a[i]<<" ";
        }
    }
    return 0;
}
