#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
int A, B, C, m;
int s[N], b[N], op[N / 2][7], tmp[N];
int get(int i, int j, int k)
{
    return (i * B + j) * C + k;
}
void add(int d[], int x1, int x2, int y1, int y2, int z1, int z2, int c)
{
    d[get(x1, y1, z1)] += c;
    d[get(x1, y1, z2 + 1)] -= c;
    d[get(x1, y2 + 1, z1)] -= c;
    d[get(x1, y2 + 1, z2 + 1)] += c;
    d[get(x2 + 1, y1, z1)] -= c;
    d[get(x2 + 1, y1, z2 + 1)] += c;
    d[get(x2 + 1, y2 + 1, z1)] += c;
    d[get(x2 + 1, y2 + 1, z2 + 1)] -= c;
}
bool check(int mid)
{
    memcpy(tmp, b, sizeof b);
    for (int i = 0; i < mid; i++) {
        int x1 = op[i][0], x2 = op[i][1], y1 = op[i][2], y2 = op[i][3],
            z1 = op[i][4], z2 = op[i][5], c = op[i][6];
        add(tmp, x1, x2, y1, y2, z1, z2, -c);
    }
    memset(s, 0, sizeof s);
    for (int i = 1; i <= A; i++) {
        for (int j = 1; j <= B; j++) {
            for (int k = 1; k <= C; k++) {
                s[get(i, j, k)] =
                    tmp[get(i, j, k)] + s[get(i - 1, j, k)] +
                    s[get(i, j - 1, k)] - s[get(i - 1, j - 1, k)] +
                    s[get(i, j, k - 1)] - s[get(i - 1, j, k - 1)] -
                    s[get(i, j - 1, k - 1)] + s[get(i - 1, j - 1, k - 1)];
                if (s[get(i, j, k)] < 0)
                    return true;
            }
        }
    }
    return false;
}
int main()
{
    cin >> A >> B >> C >> m;
    for (int i = 1; i <= A; i++) {
        for (int j = 1; j <= B; j++) {
            for (int k = 1; k <= C; k++) {
                cin >> s[get(i, j, k)];
                add(b, i, i, j, j, k, k, s[get(i, j, k)]);
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 7; j++) {
            cin >> op[i][j];
        }
    }

    int l = 1, r = m;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }
    cout << l << endl;
    return 0;
}
