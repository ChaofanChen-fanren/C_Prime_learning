
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string s;
    while (n) {
        s += (char)((n - 1) % 26 + 'A');
        n = (n - 1) / 26;
    }
    reverse(s.begin(), s.end());
    cout << s << endl;
    return 0;
}
