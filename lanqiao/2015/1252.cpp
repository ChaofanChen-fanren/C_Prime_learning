#include <bits/stdc++.h>
using namespace std;
bool check(int x)
{
    bool st[10] = {0};
    int  a = x * x, b = x * x * x;
    while (a) {
        if (st[a % 10])
            return false;
        st[a % 10] = true;
        a /= 10;
    }
    while (b) {
        if (st[b % 10])
            return false;
        st[b % 10] = true;
        b /= 10;
    }
    for(int i = 0;i <= 9;i++){
        if(!st[i]) return false;
    }
    return true;
}
int main()
{
    for (int i = 0; i < 1000; i++) {
        if(check(i)){
            cout << i << endl;
            //cout << i * i << " " << i * i * i << endl;

            return 0;
        }
    }
}
