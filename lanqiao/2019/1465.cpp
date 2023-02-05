#include <bits/stdc++.h>
#include <string>
using namespace std;
int main()
{
    int res = 0;
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        string s = to_string(i);
        if (s.find('2') != string::npos || s.find('0') != string::npos ||
            s.find('1') != string::npos || s.find('9') != string::npos)
            res += i;
    }
    cout << res << endl;
    return 0;
}
