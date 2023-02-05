#include <bits/stdc++.h>
using namespace std;
int main()
{
    int sum = 0;
    for (int i = 1,j = 1;; i += 2,j++) {
        sum += i;
        if (sum >= 108) {
            cout << j << endl;
            break;
        }
    }

    return 0;
}
