#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
    double sum1 = 0, sum2 = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x >= 60) {
            sum1++;
            if (x >= 85)
                sum2++;
        }
    }

    printf("%d%\n", (int)round(sum1 * 100 / n));
    printf("%d%\n", (int)round(sum2 * 100 / n));
    return 0;
}
