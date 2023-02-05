#include <bits/stdc++.h>
using namespace std;
const int N = 8010;
int primes[N], cnt;
int st[N];
int main()
{
    int n = 5000;
    for (int i = 2; i <= n; i++) {
        if (!st[i])
            primes[cnt++] = i;
        for (int j = 0; primes[j] <= n / i; j++) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0)
                break;
        }
    }
    set<int> s;
    for (int i = 0; i < cnt; i++) {
        s.insert(primes[i]);
        cout<<primes[i]<<endl;
    }

    for (int k = 1;; k++) {
        for (auto v : s) {
            int cnt = 0;
            for (int i = v; i < N; i += k) {
                if (s.count(i))
                    cnt++;
                else
                    break;
            }
            if (cnt == 10) {
                cout << k << endl;
                return 0;
            }
        }
    }

    return 0;
}
