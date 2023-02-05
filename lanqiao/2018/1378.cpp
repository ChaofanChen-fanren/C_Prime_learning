#include <bits/stdc++.h>
#include <climits>
#include <string>
using namespace std;
const int N = 1010;
char g[N][N];
void slove(int n)
{
    memset(g, 0, sizeof g);
    string s = "";
    int sz = 4 * n - 4;
    for (int i = 1;; i++) {
        if (s.size() >= sz)
            break;
        s += to_string(i);
    }
    cout << s << endl;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n + i - 1; j++) {
            g[i][j] = '.';
        }
        g[i][n - i + 1] = s[cnt++];
    }

    for (int i = 2; i <= 2 * n - 1; i++)
        g[n][i] = s[cnt++];

    for (int i = n - 1, j = 2 * n - 2; i >= 2; i--, j--)
        g[i][j] = s[cnt++];

    for (int i = 1; i <= n; i++) {
        printf("%s\n", g[i] + 1);
    }
}
int main()
{
    int n;
    while (cin >> n) {
        slove(n);
    }
    return 0;
}
