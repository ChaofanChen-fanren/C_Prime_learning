#include <bits/stdc++.h>
using namespace std;
const int N = 500010;
#define double long double
int a[N];
int n;
double m;
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    double res = 0, avg = m * 1.0 / n;

    for (int i = 0; i < n; i++) {
        double t = m * 1.0 / (n - i);
        if (a[i] <= t) {
            res += (double)(a[i] - avg) * (a[i] - avg);
            m -= a[i];
        }
        else {
            res += (double)(t - avg) * (t - avg);
            m -= t;
        }
    }

    printf("%.4llf", sqrt(res / n));
    return 0;
}
