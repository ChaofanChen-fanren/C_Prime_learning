#include <bits/stdc++.h>
using namespace std;
int main()
{
    // 乘积的结果0的个数转换为
    // p1^n1*p2^n2...pn^nn = ()*10^res => ()*5^i*2^j = ()*10*min(i,j);
    int count2 = 0, count5 = 0;
    for (int i = 0; i < 100; i++) {
        int num;
        cin >> num;
        while (num % 2 == 0) {
            count2++;
            num /= 2;
        }
        while (num % 5 == 0) {
            count5++;
            num /= 5;
        }
    }

    cout << min(count2, count5) << endl;
    return 0;
}
