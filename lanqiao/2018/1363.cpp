#include <bits/stdc++.h>
using namespace std;
const int N = 110;
char s[N];
int gettime()
{
    int sum1 = 0, sum2 = 0;
    int h1, m1, s1, h2, m2, s2, d = 0;
    // scanf("%d:%d:%d %d:%d:%d (+%d)", &h1, &m1, &s1, &h2, &m2, &s2, &d);
    string str;
    getline(cin, str);
    if (str.back() != ')')
        str += " (+0)";

    sscanf(str.c_str(), "%d:%d:%d %d:%d:%d (+%d)", &h1, &m1, &s1, &h2, &m2, &s2,
           &d);
    sum1 = h1 * 3600 + m1 * 60 + s1;
    sum2 = h2 * 3600 + m2 * 60 + s2 + d * 24 * 3600;
    return sum2 - sum1;
}
int main()
{
    int n;
    cin >> n;
    getchar();
    while (n--) {
        int sum = (gettime() + gettime()) / 2;
        int h = sum / 3600, m = sum % 3600 / 60, s = sum % 60;

        printf("%02d:%02d:%02d\n", h, m, s);
    }
}
