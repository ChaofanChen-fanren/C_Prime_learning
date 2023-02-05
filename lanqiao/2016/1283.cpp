#include <bits/stdc++.h>
using namespace std;
int main()
{
    for (int i = 1; i <= 236; i++) {
        int s = 0;
        for (int j = i; j; j++) {
            s += j;
            if (s == 236) {
                cout << i << endl;
                return 0;
            }
            if(s > 236) break;
        }
    }
    return 0;
}
