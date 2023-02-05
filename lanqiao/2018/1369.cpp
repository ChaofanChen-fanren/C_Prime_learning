#include <bits/stdc++.h>
using namespace std;
const int N = 35;
int s[N];
int main()
{
    int n = 10;
    while (n--) {
        for (int i = 0; i < 32; i++)
            cin >> s[i];

        for (int i = 0; i < 32; i++) {
            for (int j = 7; j >= 0; j--) {
                if (s[i] >> j & 1) {
                    cout << "*";
                }
                else {
                    cout << " ";
                }
            }
            if (i & 1)
                cout << endl;
        }
    }

    // 9^9= ?
    long long res = 1;
    for (int i = 0; i < 9; i++) {
        res = res * 9;
    }
    cout << res << endl;
    return 0;
}
