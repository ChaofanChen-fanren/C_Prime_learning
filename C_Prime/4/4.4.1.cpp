#include <iostream>
#include <vector>
using namespace std;
int func()
{
    return 2;
}
int main()
{
    // = 
    int val = 1, ival, val1;
    ival = val1 = val;
    cout << ival << val1 << val << endl;

    int i = 0;
    if ((i = func()) != 2)
    { // = lower priority
        cout << i << endl;
    }

    // i++ ++i
    vector<int> v = {1, 2, 3, 4};

    auto pbeg = v.begin();
    while(pbeg != v.end() && *pbeg >= 0)
        cout << *pbeg++ << endl;

    return 0;
}
