#include <iostream>
using namespace std;
int main()
{
    int ival = 1024;
    int &refVal = ival;
    cout << ival << " " << refVal << endl;
    refVal = 2;
    cout << ival << " " << refVal << endl;

    int &refVal1 = refVal;
    ival = 10;
    cout << ival << " " << refVal << " " << refVal1 << endl;

    int a = 1.1;
    cout << a << endl;

    // int i = 0, &r1 = i;
    // double d = 0,&r2 = d;
    // r2 = 3.14; //d = 3.14
    // r2 = r1;   // d = i;
    // i = r2;    // i = d;
    // r1 = d;    // i = d;
    // cout << i << " " << r1 << " " << d << " " << r2 << endl;

    int i, &ri = i;
    i = 5;
    ri = 10;
    cout << i << " " << ri << endl;

    return 0;
}
