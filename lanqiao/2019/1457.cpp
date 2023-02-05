#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100010;
int a[N];
int n;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    ll resn = a[0], height = 1,h = 1;

    for (int i = 1;i <= n;i <<= 1) {
        ll sum = 0;
        for (int j = i;j <= 2*i - 1 && j <= n;j++) {  
            sum += a[j];
        }
        if (resn < sum) {
            resn = sum;
            height = h + 1;
        }
        h++;
    }

    cout << height << endl;
    return 0;
}
