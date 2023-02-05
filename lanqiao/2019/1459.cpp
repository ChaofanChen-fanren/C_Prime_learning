#include <bits/stdc++.h>
using namespace std;
const int N = 2000010,M = 100010;
int p[N], a[M];
int n;
int find(int a)
{
    if (a != p[a])
        p[a] = find(p[a]);
    return p[a];
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 1; i < N; i++)
        p[i] = i;

    for (int i = 0; i < n; i++) {
        int fa = find(a[i]);
        a[i] = fa;
        p[fa] = find(a[i] + 1);
        cout<<a[i]<<" ";
    }
    cout << endl;
    return 0;
}
