#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 300010;
int t, n;
ll s[N], a[N];
bool st[N];
int main()
{
    cin >> t;
    while (t--) {
        cin >> n;
        memset(st, 0, sizeof st);
        for (int i = 1; i <= n; i++) {
            cin >> s[i];
            s[i] += s[i - 1];
        }
        ll s0 = s[0], sn = s[n];

        if (s0 > sn) {
            swap(s0, sn);
        }

        sort(s, s + n + 1);

        for (int i = 0; i <= n; i++)
            if (s[i] == s0) {
                s0 = i;
                break;
            }
        for (int i = n; i >= 0; i--)
            if (s[i] == sn) {
                sn = i;
                break;
            }

        int l = 0, r = n;
        for (int i = s0; i >= 0; i -= 2) {
            a[l++] = s[i];
            st[i] = 1;
        }

        for (int i = sn; i <= n; i += 2) {
            a[r--] = s[i];
            st[i] = 1;
        }

        for (int i = 0; i <= n; i++) {
            if (!st[i])
                a[l++] = s[i];
        }

        ll res = 0;
        for (int i = 1; i <= n; i++) {
            res = max(res, abs(a[i] - a[i - 1]));
        }
        cout << res << endl;
    }
    return 0;
}
