#include <bits/stdc++.h>
using namespace std;
bool is_prime(int n)
{
    if (n < 2)
        return 0;
    for (int i = 2; i <= n / i; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}
int main()
{
    int n = 2019;
    for (int i = 2;; i++) {
        if (is_prime(i)) {
            n--;
            if (!n) {
                cout << i << endl;
                return 0;
            }
        }
    }
}
