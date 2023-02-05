#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 10010;

int n;

int a[N];

int main()
{
    while (~scanf("%d", &n)) {
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);

        int sum = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] != i) {
                int j = i;
                while (a[j] != j) {
                    swap(a[a[j]], a[j]);
                    //cout << a[j] << endl;
                    sum++;
                }
            }
        }

        printf("%d\n", sum);
    }
    return 0;
}
