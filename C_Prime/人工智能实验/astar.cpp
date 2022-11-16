#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;
int cnt_1 = 0;             // 扩展结点数
int cnt_2 = 0;             // 生成结点数
// int h(string state) // 估价函数 各数码移动到目标位置的距离之和
// {
//   int res = 0;
//   for (int i = 0; i <= 8; i++) {
//     if (state[i] != 'x') {
//       int s = state[i] - '1';
//       res += abs(i % 3 - s % 3) + abs(i / 3 - s / 3);
//     }
//   }
//   return res;
// }
// int h(string state)  // 估价函数 计算不在位的个数
// {
//     string end = "1238x4765";  // 最终的形态
//     int res = 0;
//     for (int i = 0; i <= 8; i++) {
//         if (state[i] != end[i]) {
//             res++;
//         }
//     }
//     return res;
// }
int h(string state) //估价函数0
{
    return 0;
}
string astar(string start)
{
    string end = "1238x4765";  // 最终的形态
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    char op[] = {'u', 'r', 'd', 'l'};
    unordered_map<string, int> dist;
    unordered_map<string, pair<string, char>> prev;
    priority_queue<pair<int, string>, vector<pair<int, string>>,
                   greater<pair<int, string>>>
        heap;

    dist[start] = 0;
    heap.push({0 + h(start), start});
    while (heap.size()) {
        auto t = heap.top();
        heap.pop();
        string state = t.second;
        int step = dist[state];
        int a, b;
        cnt_1++;  // 扩展节点数

        if (state == end)
            break;
        // cout<<state<<endl;
        for (int i = 0; i <= 8; i++) {
            if (state[i] == 'x') {
                a = i / 3;
                b = i % 3;
                break;
            }
        }
        for (int i = 0; i < 4; i++) {
            int x = a + dx[i], y = b + dy[i];

            if (x >= 0 && x < 3 && y >= 0 && y < 3) {
                swap(state[a * 3 + b], state[x * 3 + y]);
                if (!dist.count(state) || dist[state] > step + 1) {
                    prev[state] = {t.second, op[i]};
                    dist[state] = step + 1;
                    cnt_2++;  // 生成节点数
                    heap.push({dist[state] + h(state), state});
                }
                swap(state[a * 3 + b], state[x * 3 + y]);
            }
        }
    }
    string res = "";
    while (end != start) {
        res += prev[end].second;
        end = prev[end].first;
    }
    reverse(res.begin(), res.end());
    return res;
}
int main()
{
    time_t start, end;
    start = clock();  // 开始计时
    string g, que;
    for (int i = 0; i <= 8; i++) {
        char c;
        cin >> c;
        g += c;
        if (c != 'x')
            que += c;
    }

    int t = 0;
    for (int i = 0; i <= 7; i++) {
        for (int j = i + 1; j <= 7; j++) {
            if (que[i] > que[j])
                t++;
        }
    }
    if (!(t & 1)) //如果逆序对为偶数为无解  因为最终状态为逆序对为奇数
        cout << "unsolvable" << endl;
    else {
        cout << "u : 上 d: 下 l: 左  r:右" << endl;
        cout << "操作步骤: " << astar(g) << endl;
        cout << "扩展结点: " << cnt_1 << endl;
        cout << "生成结点: " << cnt_2 << endl;
    }
    end = clock();  // 计时结束
    double duration = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << "运行时间 :" << duration << endl;
    return 0;
}
