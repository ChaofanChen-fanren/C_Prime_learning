#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int main()
{
    int pre = 0, ci = 1;
    int n, m;
    cin >> n >> m;
    while(n--){
        int val;
        cin >> val;
        int res = ((m % (ci * val)) - pre) / ci;
        cout << res << " ";
        pre += ci * res;
        ci *= val;
    }
    cout << endl;
    return 0;
}
