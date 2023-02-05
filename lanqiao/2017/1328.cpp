#include <bits/stdc++.h>
#include <string>
using namespace std;
int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
set<string> res;
void check(int y, int m, int d)
{
    if (y < 1960 || y > 2059)
        return;

    if (m <= 0 || m >= 13)
        return;

    if (m != 2) {
        if (d > months[m] || d <= 0)
            return;
    }
    else {
        bool isleapyear = y % 4 == 0 && y % 100 != 0 || y % 400 == 0;
        if (d > months[m] + isleapyear || d <= 0)
            return;
    }

    string date = to_string(y) + '-';
    if (m <= 9)
        date += '0' + to_string(m) + '-';
    else
        date += to_string(m) + '-';
    if (d <= 9)
        date += '0' + to_string(d);
    else
        date += to_string(d);

    res.insert(date);
    // printf("%04d-%02d-%02d\n", y, m, d);
}
int main()
{
    string s;
    cin >> s;
    int a = stoi(s.substr(0, 2));
    int b = stoi(s.substr(3, 2));
    int c = stoi(s.substr(6, 2));
    // cout << a << b << c << endl;

    // 1.
    check(a + 1900, b, c);
    check(a + 2000, b, c);
    // 2.
    check(c + 1900, a, b);
    check(c + 2000, a, b);
    // 3.
    check(c + 1900, b, a);
    check(c + 2000, b, a);

    for (auto date : res) {
        cout << date << endl;
    }
    return 0;
}
