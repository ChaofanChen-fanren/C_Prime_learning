#include <bits/stdc++.h>
using namespace std;
int main()
{
    int res = 0;
    for (int i = 1; i <= 2020; i++) {
        for (int j = 1; j <= 2020; j++) {
            if(__gcd(i,j) == 1) res++;
        }
    }
    cout<<res<<endl;
    return 0;
}
