#include <bits/stdc++.h>
#include <string>
using namespace std;
int main()
{
    long long res = 0;
    for (int i = 1; i <= 2019; i++) {
        string s = to_string(i);
        if (s.find('2') != string::npos || s.find('0') != string::npos ||
            s.find('1') != string::npos || s.find('9') != string::npos)
            res += (long long) i * i * i;
    }
    cout << res << endl;
    return 0;
}
