#include <bits/stdc++.h>
#include <string>
using namespace std;
int main()
{
    int res = 0;
    for (int i = 1; i <= 2019; i++) {
        for (int j = i + 1; j <= 2019; j++) {
            if (i + j >= 2019)
                continue;
            int k = 2019 - i - j;
            if (k <= j)  // i < j < k
                continue;
            string s = to_string(i) + to_string(j) + to_string(k);
            if (s.find('2') != string::npos || s.find('4') != string::npos)
                continue;
            if (i + j + k == 2019) {
                res++;
            }
        }
    }
    cout << res << endl;
    return 0;
}
