#include <bits/stdc++.h>
#include <cstdio>
#include <string>
using namespace std;
const int N = 1000010;
int sa[N];  // 求Alice 出现的坐标标示为1 当一个Bob出现求sa[l - r]

int main()
{
    int k;
    string str;
    cin >> k;
    getchar();
    getline(cin, str);
    long long res = 0;

    for (int i = 0; i < str.size(); i++) {
        i = str.find("Alice", i);
        if (i == string::npos)
            break;
        if (isalpha(str[i + 5])) {
            i = i + 5;
            continue;
        }
        sa[i + 1] = true;
    }

    for (int i = 1; i <= str.size(); i++) {
        sa[i] += sa[i - 1];
    }

    for (int i = 0; i < str.size(); i++) {
        i = str.find("Bob", i);
        if (i == string::npos)
            break;

        if (isalpha(str[i + 3])) {
            i = i + 3;
            continue;
        }
        // A ... Bob ... A
        int l = max(0, i - k - 5), r = min(i + 3 + k, (int)str.size());

        res += sa[r] - sa[l - 1];
    }

    cout << res << endl;
    return 0;
}
