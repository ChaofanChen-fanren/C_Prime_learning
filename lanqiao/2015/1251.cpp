#include <bits/stdc++.h>
using namespace std;
int  year, month, day, n;
int  m[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool isleapyear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}
void slove()
{
    while (n--) {
        day++;

        if (month == 2) {
            if (m[month] + isleapyear(year) < day)
                month++, day = 1;
        }
        else {
            if (m[month] < day)
                month++, day = 1;
        }

        if (month > 12) {
            month = 1;
            year++;
        }
    }
    printf("%4d-%02d-%02d\n", year, month, day);
}
int main()
{
    while (cin >> year >> month >> day >> n) {
        slove();
    }
    return 0;
}
