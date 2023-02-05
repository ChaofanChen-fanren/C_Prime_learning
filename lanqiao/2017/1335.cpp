#include <bits/stdc++.h>
#include <queue>
using namespace std;
const int N = 60;
char desk[N];
int len;
string sa, sb;
int get(char c)
{
    if (c >= '2' && c <= '9')
        return c - '0';
    switch (c) {
        case 'A': return 1;
        case 'X': return 10;
        case 'J': return 11;
        case 'Q': return 12;
        case 'K': return 13;
    }
    return -1;
}
bool check(char c, queue<char>& a, stack<int> stk[])
{
    int t = get(c);
    while (stk[t].size()) {
        auto pre = stk[t].top();
        // stk[t].pop();

        a.push(c);
        // if(len - 1 < pre) continue;
        // cout<<"-----"<<len<<pre<<endl;
        for (int i = len - 1; i >= pre; i--) {
            a.push(desk[i]);
            stk[get(desk[i])].pop();  // 最关键:除掉每一个出去的记录
        }
        len = pre;
        return true;
    }
    return false;
}
void print()
{
    for (int i = 0; i < len; i++) {
        cout << desk[i] << " ";
    }
    cout << endl;
}
int slove()
{
    queue<char> a, b;
    stack<int> stk[14];
    memset(desk, 0, sizeof desk);
    for (int i = 0; i < sa.size(); i++)
        a.push(sa[i]);
    for (int i = 0; i < sb.size(); i++)
        b.push(sb[i]);

    // if (a.size()) {
    //     while (a.size()) {
    //         cout << a.front();
    //         a.pop();
    //     }
    // }
    // if(b.size()){
    //     while (b.size()) {
    //         cout << b.front();
    //         b.pop();
    //     }
    // }
    int cnt = 1;
    while (a.size() && b.size()) {
        if (cnt & 1) {
            char c = a.front();
            a.pop();
            if (!check(c, a, stk)) {
                desk[len] = c;
                stk[get(c)].push(len);
                len++;
            }
            else {
                cnt++;
            }
        }
        else {
            char c = b.front();
            b.pop();
            if (!check(c, b, stk)) {
                desk[len] = c;
                stk[get(c)].push(len);
                len++;
            }
            else {
                cnt++;
            }
        }
        // print();
        cnt++;
        if (cnt >= 100000) {
            cout << "-1" << endl;
            return 0;
        }
    }
    if (a.size()) {
        while (a.size()) {
            cout << a.front();
            a.pop();
        }
    }
    else if (b.size()) {
        while (b.size()) {
            cout << b.front();
            b.pop();
        }
    }
    cout << endl;
    return 0;
}
int main()
{
    while (cin >> sa >> sb) {
        slove();
    }
    return 0;
}
