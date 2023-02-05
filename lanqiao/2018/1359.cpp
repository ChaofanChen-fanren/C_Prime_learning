#include <bits/stdc++.h>
using namespace std;
int main()
{
    // 2^19/2^19 + 2^18/2^19 ... + 1/2^19
    int a = (1 << 20) - 1, b = 1 << 19;
    int d = __gcd(a, b);

    cout << a / d << "/" << b / d << endl;
    return 0;
}
