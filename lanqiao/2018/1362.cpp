#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    // 暴力枚举比x小的数
    long long x = 59084709587505;
    ll y = 0;
    ll i = 0;
    for (ll a = 1; a < x; a *= 3) {
        for (ll b = 1; b < x; b *= 5) {
            for (ll c = 1; c < x; c *= 7) {
                y = a * b * c;
                if (y < x && y > 0) {
                    i++;
                }
            }
        }
    }
    printf("%lld\n", i);

    // bfs
    std::priority_queue<ll> q;
    set<ll> s;
    q.push(1);
    while (q.size()) {
        auto t = q.top();
        q.pop();

        for (int i = 3; i <= 7; i += 2) {
            if (t * i <= x && !s.count(t * i)) {
                q.push(t * i);
                s.insert(t * i);
            }
        }
    }
    cout << s.size() << endl;
    return 0;
}
