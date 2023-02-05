#include <bits/stdc++.h>
using namespace std;
int main()
{
    int num[10] = {0};
    for (int i = 1; i <= 9; i++)
        num[i] = i;
    int res = 0;
    do {
        int a = num[1] + num[2] + num[3] + num[4];
        int b = num[4] + num[5] + num[6] + num[7];
        int c = num[7] + num[8] + num[9] + num[1];
        if (a == b && b == c)
            res++;

    } while (next_permutation(num + 1, num + 1 + 9));
    cout << res / 6 << endl;  // 旋转3种，镜像2种

    return 0;
}
