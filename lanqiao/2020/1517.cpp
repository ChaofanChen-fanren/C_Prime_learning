#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int a[N];
int main()
{
    int n;
    cin >> n;
    double avg = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        avg += a[i];
    }

    sort(a, a + n);
    cout << a[n - 1] << endl;
    cout << a[0] << endl;

    printf("%.2lf", avg / n);
    return 0;
}
