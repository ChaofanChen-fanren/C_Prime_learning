#include <stdio.h>
#include <string.h>
int ishui(int n)
{  // 判断是否为回文数
    int tem = n;
    int flag = 1;
    int num = 10000000;
    while (n != 0) {
        if (n / num != n % 10) {
            flag = 0;
        }
        n /= 10;
        num /= 10;
        n %= num;
        num /= 10;
    }
    tem /= 10000;
    if (tem / 1000 == tem / 10 % 10 && tem / 100 % 10 == tem % 10 && flag)
        flag = 2;
    return flag;
}
int judgedate(int n)
{  // 判断日期是否有效
    int tem = n;
    int flag = 1;
    int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    n /= 10000;
    if (tem / 100 % 100 <= 0 || tem / 100 % 100 > 12)
        flag = 0;
    if (n % 4 == 0 && n % 100 != 0 || n % 400 == 0) {
        if (tem % 100 >= 29)
            flag = 0;
    }
    else {
        if (tem / 100 % 100 > 0 && tem / 100 % 100 <= 12) {
            if (day[tem / 100 % 100 - 1] <= tem % 100)
                flag = 0;
        }
    }
    return flag;
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int year, i, count1 = 0, count2 = 0;
        scanf("%d", &year);
        i = year + 1;
        while (count1 < 1) {  // 枚举终止条件之一，只需一个回文日期
            if (ishui(i) != 0 && judgedate(i)) {
                printf("%d\n", i);
                count1++;
            }
            i++;
        }
        i -= 1;
        while (count2 < 1) {  // 枚举终止条件2，日期为回文数且有固定格式
            if (ishui(i) == 2 && judgedate(i)) {
                printf("%d", i);
                count2++;
            }
            i++;
        }
    }

    return 0;
}
