#include <bits/stdc++.h>
using namespace std;
int main()
{
    //   a b c d
    // + e f g b
    // e f c b h
    int d[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    do {
        if (!d[4])
            continue;
        int a = d[0] * 1000 + d[1] * 100 + d[2] * 10 + d[3];
        int b = d[4] * 1000 + d[5] * 100 + d[6] * 10 + d[1];
        int c = d[4] * 10000 + d[5] * 1000 + d[2] * 100 + d[1] * 10 + d[7];
        if (a + b == c) {
            // cout << a << " " << b << " " << c << endl;
            cout << b << endl;
            break;
        }
    } while (next_permutation(d, d + 10));

    // // 组合型 10选 8;
    // bool st[10] = {0};
    // for (int i = 0; i < 8; i++)
    //     st[i] = 1;
    // do{
    //     for (int i = 0; i < 10; i++) {
    //         if(st[i]){
    //             cout<<i<<" ";
    //         }
    //     }
    //     cout << endl;
    // }while(prev_permutation(st,st + 10));
    return 0;
}
