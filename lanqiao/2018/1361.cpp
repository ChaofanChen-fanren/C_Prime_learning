#include <bits/stdc++.h>
#include <vector>
using namespace std;
// 大数乘积直接乘
vector<int> mul(vector<int> a, int b)
{
    vector<int> C;
    long long t = 0;
    for (int i = 0; i < a.size(); i++) {
        t += (long long)a[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }
    while (t) {
        C.push_back(t % 10);
        t /= 10;
    }
    return C;
}
int main()
{
    int n = 100;
    int num;
    cin >> num;
    vector<int> v;
    for (int i = num; i; i /= 10)
        v.push_back(i % 10);
    while (--n) {
        cin >> num;
        v = mul(v, num);
    }
    int res = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == 0)
            res++;
        if (v[i] != 0)
            break;
    }
    cout << res << endl;
    return 0;
}
