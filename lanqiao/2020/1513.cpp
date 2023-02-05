#include <bits/stdc++.h>
#include <cstdio>
#include <locale>
using namespace std;
int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool isleapyear(int y)
{
    return y % 4 == 0 && y % 100 != 0 || y % 400 == 0;
}
int main()
{
    int y = 2000, m = 1, d = 1;

    int res = 0, day = 5;

    while (y != 2020 || m != 10 || d != 1) {
        res++;
        if (day == 0 || d == 1)
            res++;
        // printf("%04d:%02d:%02d\n", y, m, d);
        d++;
        day = (day + 1) % 7;

        if (m != 2) {
            if (months[m] < d) {
                m++;
                d = 1;
            }
        }
        else {
            if (months[m] + isleapyear(y) < d) {
                m++;
                d = 1;
            }
        }

        if (m > 12) {
            m = 1;
            y++;
        }
    }

    res += 2;
    // cout << day + 1 << endl;
    cout << res << endl;
    return 0;
}
