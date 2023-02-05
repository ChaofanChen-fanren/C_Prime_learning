#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long res = 0;
    long long r = 50000;
    for (long long i = 1, j = r; i <= r; i++) {
        while ((i * i + j * j) > r*r)
            j--;
        //cout << j << endl;
        res += j;
    }
    cout << res * 4;
    return 0;
}
