#include <bits/stdc++.h>
using namespace std;
int main()
{
    for (int j = 6;; j++) {
        int i = j;
        if (i % 5 == 1) {
            i = i - i / 5 - 1;
            if (i % 5 == 2) {
                i = i - i / 5 - 2;
                if (i % 5 == 3) {
                    i = i - i / 5 - 3;
                    if (i % 5 == 4) {
                        i = i - i / 5 - 4;
                        if (i % 5 == 0 && i >= 5) {
                            cout << j << endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }
}
