#include <bits/stdc++.h>
using namespace std;
int main()
{
    int sum = 1225;

    for (int i = 1; i < 50; i++) {
        for (int j = i + 2; j < 50; j++) {
            int s = sum - i - i - 1 - j - j - 1;
            s += i * (i + 1) + j * (j + 1);
            if (s == 2015 && i != 10) {
                // cout << i << " " << j << endl;
                cout << i << endl;
            }
        }
    }
    return 0;
}
