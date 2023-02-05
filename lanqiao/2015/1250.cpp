#include <bits/stdc++.h>
using namespace std;
bool slove(int n)
{
    int flag = false;
    for (int a = 1; a <= 100; a++) {
        for (int b = a; b <= 100; b++) {
            for (int c = b; c <= 100; c++) {
                if (a * a + b * b + c * c == n) {
                    cout << a << " " << b << " " << c << endl;
                    flag = true;
                }
            }
        }
    }
    return flag;
}
int main()
{
    int n;
    while(cin>>n){
        if(!slove(n))
            cout << "No Solution" << endl;
    }
    return 0;
}
