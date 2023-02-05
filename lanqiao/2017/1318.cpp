#include <bits/stdc++.h>
using namespace std;
const int N = 20;
string str, ed;
int bfs()
{
    queue<string> q;
    unordered_map<string, int> d;

    d[str] = 1;
    q.push(str);

    while (q.size()) {
        auto t = q.front();
        q.pop();
        int k = t.find('0');

        if (t == ed)
            return d[t] - 1;
        int dist = d[t];

        //*左右两边跳
        for (int i = k - 2; i <= k + 2; i++) {
            if (i == k)
                continue;
            int id = (i + 9) % 9;
            // cout << id << endl;
            swap(t[k], t[id]);
            if (!d[t]) {
                d[t] = dist + 1;
                // cout << t << endl;
                q.push(t);
            }
            swap(t[k], t[id]);
        }
        // break;
    }
    return -1;
}
int main()
{
    str = "012345678", ed = "087654321";
    cout << bfs() << endl;
    return 0;
}
