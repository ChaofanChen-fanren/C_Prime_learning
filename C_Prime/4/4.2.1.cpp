#include <iostream>
using namespace std;

int main()
{
    //overflow
    short sval = 32767;
    sval += 1;
    cout << sval << endl;

    // %  /     m%n(m%-n) -m%n
    cout << -21 % 8 << endl;
    cout << 21 % -6 << endl;
    cout << 21 % 6 << endl;

    cout << 21 / 6 << endl;
    cout << 21 / -7 << endl;
    cout << -21 / -7 << endl;
    return 0;
}
