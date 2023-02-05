#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long res = 0;
    int len = 0, temp = 1;
    for (int i = 1; i <= 100; i++) {
        len += temp;
        res += len;
        temp++;
    }
    cout << res << endl;
    return 0;
}
