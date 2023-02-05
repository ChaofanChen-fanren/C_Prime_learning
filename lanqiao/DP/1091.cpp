#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int f1[N], f2[N], a[N];
int n;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++) {
        f1[i] = 1;
        for (int j = 0; j < i; j++)
            if (a[j] < a[i])
                f1[i] = max(f1[i], f1[j] + 1);
    }

    int res = 1;
    for (int i = n - 1; i >= 0; i--) {
        f2[i] = 1;
        for (int j = n - 1; j > i; j--) {
            if (a[j] < a[i])
                f2[i] = max(f2[i], f2[j] + 1);
        }
        //cout << f1[i] << " " << f2[i] << endl;
        res = max(res, f1[i] + f2[i] - 1);
    }

    cout << n - res << endl;
    return 0;
}
