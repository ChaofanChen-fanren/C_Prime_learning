#include <bits/stdc++.h>
using namespace std;
int main()
{
    int w, a, b;
    while(cin >> w >> a >> b){
        int x1 = (a - 1) / w, x2 = (b - 1) / w;
        int y1 = (a - 1) % w, y2 = (b - 1) % w;
        if (x1 % 2)
            y1 = w - y1 - 1;
        if (x2 % 2)
            y2 = w - y2 - 1;
        cout << abs(x1 - x2) + abs(y1 - y2) << endl;
    }
    return 0;    
}
