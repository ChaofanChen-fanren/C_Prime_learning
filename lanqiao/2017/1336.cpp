#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 100010;
struct Pict
{
    int w, h;
} p[N];
int f[N];
int w, n;
int get(int wide, int k, int& h)
{
    for (; k < n; k++) {
        if (wide < p[k].w) {
            h = max(h, (int)ceil((double)p[k].h * wide / p[k].w));
            wide = 0;
        }
        else {
            h = max(h, p[k].h);
            wide -= p[k].w;
        }
        if (wide == 0)
            return k + 1;
    }
    return k;
}
int main()
{
    while (cin >> w >> n) {
        for (int i = 0; i < n; i++) {
            cin >> p[i].w >> p[i].h;
        }
        for (int i = n - 1; i >= 0; i--) {
            int h = 0;
            int k = get(w, i, h);
            f[i] = h + f[k];
        }

        int height = 0, lheight = 0, wide = w;
        int res = 1e7;
        for (int i = 0; i < n; i++) {
            int h = lheight;
            int k = get(wide, i + 1, h);
            res = min(res, h + f[k] + height);

            if (p[i].w > wide) {
                lheight =
                    max(lheight, (int)ceil((double)p[i].h * wide / p[i].w));
                wide = 0;
            }
            else {
                lheight = max(lheight, p[i].h);
                wide -= p[i].w;
            }

            if (wide == 0) {
                wide = w;
                height += lheight;
                lheight = 0;
            }
        }
        cout << res << endl;
    }
    return 0;
}
