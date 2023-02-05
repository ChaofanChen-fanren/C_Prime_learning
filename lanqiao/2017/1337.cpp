#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
bool check(int a, int b)
{
    long long num = (long long)a * b;
    int st[10] = {0};
    while (num) {
        int t = num % 10;
        if (st[t])
            return false;
        st[t] = true;
        num /= 10;
    }

    for (int i = 1; i <= 9; i++) {
        if(!st[i]) return false;
    }
    return true;
}
int main()
{
    int a[10] = {0};
    for (int i = 1; i <= 9; i++)
        a[i] = i;
    int res = 0;
    do {
        for (int i = 2; i <= 9; i++) {
            int b = 0;
            for (int j = 1; j < i; j++) {
                b = b*10 + a[j];
            }
            int c = 0;
            for (int j = i; j <= 9; j++) {
                c = c * 10 + a[j];
            }

            if (check(b, c)) {
                res++;
                //cout<<b<<" "<<c<<" "<<(long long)b*c<<endl;
            }
        }
    } while (next_permutation(a + 1, a + 1 + 9));
    cout << res / 2 << endl;
    return 0;
}
