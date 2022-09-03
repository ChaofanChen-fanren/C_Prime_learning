#include <iostream>
using namespace std;
int main()
{
    int i = 42;
    const int &r1 = i;
    const int &r2 = 42;
    const int &r3 = r1 * 2;
    //int &r4 = r1 * 2;
    

    double dval = 3.14;
    const int &ri = dval;

    //const int *p = &dval;
    //const int &const r; must be init

    int null = 0, *p = &null;
    return 0;
}
