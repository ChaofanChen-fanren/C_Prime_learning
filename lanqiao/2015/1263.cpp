#include <bits/stdc++.h>
using namespace std;
int n, m;
int main()
{
    while (cin >> n >> m) {
        m = m + n - 1;
        int l = 1, r = m - n + 1;
        char str[2010];
        while (l <= m - n + 1) {
            for (int i = 1; i <= m; i++)
                str[i] = '.';
            str[m + 1] = '\0';
            for (int i = 0, j = l; i < n; i++, j++)
                str[j] = '*';
            for (int i = 0, j = r; i < n; i++, j++)
                str[j] = '*';
            cout << (str + 1) << endl;
            l++, r--;
        }
    }
    return 0;
}
