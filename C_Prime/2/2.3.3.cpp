#include <iostream>
using namespace std;
int main()
{
    int ival = 1024;
    int *p1 = &ival;
    int **ppi = &p1;

    cout << "The value of ival\n"
         << "direct value: " << ival << "\n"
         << "indirect value: " << *p1 << "\n"
         << "double indirect value: " << **ppi
         << endl;

    int i = 42;
    int *p;
    int *&r = p;//r is reference of point of int

    r = &i;
    *r = 0;

    int cnt = 0;
    const int sz = cnt;
    cout << sz << endl;
    return 0;
}
