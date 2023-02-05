#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int sa[N], sc[N];
int A[N], B[N], C[N];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        sa[A[i] + 1]++;
    }
    for (int i = 0; i < n; i++)
        cin >> B[i];
    for (int i = 0; i < n; i++) {
        cin >> C[i];
        sc[C[i] + 1]++;
    }
    for (int i = 1; i < N; i++) {
        sc[i] += sc[i - 1];
        sa[i] += sa[i - 1];
    }

    long long res = 0;
    for (int i = 0; i < n; i++) {
        res += (long long)sa[B[i]] * (sc[N - 1] - sc[B[i] + 1]);
    }
    cout << res << endl;
    return 0;
}
