#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 300010;
int f[N];
int main()
{
    int n, m;
    cin >> n >> m;
    f[0] = true;
    for (int i = 0; i < n; i++) {
        int w;
        cin>>w;
        for (int i = N - 1; i >= w; i--) {
            f[i] |= f[i - w];
        }
    }
    for (int i = m; i < N; i++) {
        if (f[i]) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}
