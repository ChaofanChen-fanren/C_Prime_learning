#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 2019;
    string str = "";
    while (n) {
        n--;
        str += n % 26 + 'A';
        n /=  26;
    }
    reverse(str.begin(), str.end());
    cout<<str<<endl;
    return 0;
}
