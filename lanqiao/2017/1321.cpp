#include <bits/stdc++.h>
using namespace std;
string s;
int k;
int dfs()
{
    int res = 0;
    while (k < s.size()) {
        if (s[k] == '(') {
            k++;
            res += dfs();
            k++;
        }
        else if (s[k] == '|') {
            k++;
            res = max(res, dfs());
        }
        else if (s[k] == 'x') {
            res++;
            k++;
        }
        else {
            break;
        }
    }
    cout << k << " " << res << endl;
    return res;
}
int main()
{
    cin >> s;
    cout << dfs() << endl;
    return 0;
}
