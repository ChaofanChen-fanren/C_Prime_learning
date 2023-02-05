#include <bits/stdc++.h>
#include <sys/types.h>
using namespace std;
typedef struct Complex
{
    long long r, i;
} Cp;
Cp mul(Cp a, Cp b)
{
    long long ra = a.r*b.r - (a.i * b.i);
    long long rb = a.i * b.r + b.i * a.r;
    return {ra,rb};
}
int main()
{
    Cp a = {2, 3};
    int n = 123456;
    Cp res = a;
    for (int i = 1; i < n; i++) {
        res = mul(res,a);
    }
    cout << res.r;
    if (res.i >= 0)
        cout << "+";
    cout << res.i << "i" << endl;
    return 0;
}
