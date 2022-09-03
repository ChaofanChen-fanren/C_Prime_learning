#include <iostream>
using namespace std;
int main()
{
    // using i = int;
    // i x = 1;
    // cout << x << endl;
    // int i = 0;
    // const int ci = i, &cr = ci;

    // auto b = ci;
    // auto c = cr;

    const int i = 42;
    const auto j2 = i, &k2 = i;
    

    return 0;
}
