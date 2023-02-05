#include <bits/stdc++.h>
#include <string>
#include <unordered_map>
using namespace std;
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
int bfs(string s)
{
    int a = s.find('B'), b = s.find('A');
    cout << s << endl;
    queue<string> q;
    unordered_map<string, int> d;
    d[s] = 1;
    while (q.size()) {
        auto t = q.front();
        q.pop();
        if (t.find('A') == a && t.find('B') == b)
            return d[t] - 1;

        int id = t.find(' ');
        int dist = d[t];
        int tx = id / 3, ty = id % 3;
        for (int i = 0; i < 4; i++) {
            int x = tx + dx[i], y = ty + dy[i];
            if (x < 0 || x >= 2 || y < 0 || y >= 3)
                continue;
            swap(t[id], t[x * 3 + y]);
            if (d[t] != 0) {
                d[t] = dist + 1;
                q.push(t);
            }
            swap(t[id], t[x * 3 + y]);
        }
    }
    return 0;
}
int main()
{
    string s, t;
    while (cin >> s >> t) {
        s = s + t;
        cout << bfs(s) << endl;
    }
    return 0;
}
