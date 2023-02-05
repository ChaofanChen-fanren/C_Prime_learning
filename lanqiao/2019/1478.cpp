#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n >= 20) {
        cout << "0.61803399";
        return 0;
    }

    double f1 = 0, f2 = 1, f3;
    while (n--) {
        f3 = f2 + f1;
        if (n == 0)
            printf("%.8f\n", f2 / f3);
        f1 = f2;
        f2 = f3;
    }
}
