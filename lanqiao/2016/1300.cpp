#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s = "vxvxvxvxvxvxvvx";
    int res = 777;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'v')
            res *= 2;
        else
            res -= 555;
    }
    cout << res << endl;
    return 0;
}
