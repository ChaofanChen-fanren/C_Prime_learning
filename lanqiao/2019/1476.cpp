#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long p = 1, res = 0;
    string str = "LANQIAO";

    for (int i = str.size() - 1; i >= 0; i--) {
        res += p * (str[i] - 'A' + 1);
        p *= 26;
    }

    cout << res << endl;
    return 0;
}
