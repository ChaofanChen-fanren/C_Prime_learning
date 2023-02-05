#include <bits/stdc++.h>
#include <sstream>
using namespace std;
int main()
{
    int res = 0;
    for (int i = 10000; i <= 99999; i++) {
        string s = to_string(i);
        if (s.find('4') == string::npos)
            res++;
    }
    cout << res << endl;
    return 0;
}
