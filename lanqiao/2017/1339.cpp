#include <bits/stdc++.h>
#include <vector>
using namespace std;
vector<int> num;
vector<int> dev(vector<int> a, int b, int& r)
{
    vector<int> c;
    r = 0;
    for (int i = a.size() - 1; i >= 0; i--) {
        r = r * 10 + a[i];
        c.push_back(r / 9);
        r %= 9;
    }
    reverse(c.begin(), c.end());
    while (c.back() == 0 && c.size() > 1)
        c.pop_back();
    // for (int i = c.size() - 1; i >= 0; i--) {
    //     cout << c[i];
    // }
    // cout << endl;
    return c;
}
int main()
{
    string s = "651764141421415346185";
    for (int i = s.size() - 1; i >= 0; i--)
        num.push_back(s[i] - '0');
    int r = 0;
    dev(num, 9, r);
    // cout << r << endl;
    cout << (char)((r + 9 - 1) % 9 + 'A') << endl;

    // 第2种方法
    int temp = 0;
    for (int i = 0; i < s.size(); i++) {
        temp = (temp * 10 + s[i] - '0') % 9;
    }
    cout << (char)((temp + 9 - 1) % 9 + 'A') << endl;

    return 0;
}
