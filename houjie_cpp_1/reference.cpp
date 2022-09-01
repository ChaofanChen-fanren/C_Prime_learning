#include <iostream>
using namespace std;
int main()
{
    int x = 0;
    int *p = &x;
    int &r = x;
    int x2 = 5;

    r = x2; // r cannot be re-referenced variable,this is assignment operation
    cout << "r:" << r << endl;
    cout << "x2:" << x2 << endl;
    int &r2 = r;
    return 0;
}
