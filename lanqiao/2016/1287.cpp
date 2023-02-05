#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
#define x first
#define y second
typedef pair<int, int> PII;
const int N = 5000010;
PII s[N];
int st[N];
void slove(int n)
{
    for (int i = 0; i * i <= n; i++) {
        for (int j = i; i * i + j * j <= n; j++) {
            int sum = i * i + j * j;
            if (st[sum])
                continue;
            s[sum].x = i, s[sum].y = j;
            st[sum] = true;
        }
    }
    for (int i = 0; i * i <= n; i++) {
        for (int j = i; j * j + i * i <= n; j++) {
            int sum = n - i * i - j * j;
            if (st[sum]) {
                cout << i << " " << j << " " << s[sum].x << " " << s[sum].y
                     << endl;
                return;
            }
        }
    }
}
int main()
{
    int n;
    while (cin >> n) {
        slove(n);
    }
    return 0;
}
