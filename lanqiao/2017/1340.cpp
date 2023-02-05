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
        int k = t.find('*');

        if (t == ed)
            return d[t] - 1;
        int dist = d[t];
        //*左右两边跳
        for (int i = k - 3; i <= k + 3; i++) {
            if (i < 0 || i >= t.size() || i == k)
                continue;

            swap(t[k], t[i]);
            if (!d[t]) {
                d[t] = dist + 1;
                q.push(t);
            }
            swap(t[k], t[i]);
        }
    }
    return -1;
}
int main()
{
    while (cin >> str >> ed) {
        cout << bfs() << endl;
    }
    return 0;
}
