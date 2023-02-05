#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
struct Node
{
    int t, id;
    bool operator<(const struct Node& a) const
    {
        if (id != a.id)
            return id < a.id;
        return t < a.t;
    }
} a[N];
int main()
{
    int n, d, m;
    cin >> n >> d >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i].t >> a[i].id;
    }

    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        int k = i;  // 双指针
        // cout<<"---"<<a[k].id<<endl;
        int score = 1, flag = false;
        while (i + 1 < n && a[i].id == a[i + 1].id) {
            i++;
            if (a[i].t - a[k].t >= d) {
                k++;
                score--;
            }
            score++;
            if (score >= m)
                flag = true;
        }
        if (score >= m)
            flag = true;  // score得分为1也是热帖
        if (flag)
            cout << a[i].id << endl;
    }

    return 0;
}
