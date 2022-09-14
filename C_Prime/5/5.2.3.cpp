#include <iostream>
#include <vector>
using namespace std;
int get_value()
{
    return 1;
}
int main()
{
    unsigned index;
    cin >> index;
    vector<int> ivec(10, 0);
    switch (index)
    {
    case 1:
        int ix = get_value();
        ivec[ix] = index;
        break;
    default:
        ix = ivec.size() - 1;
        ivec[ix] = index;
        break;
    }

    // unsigned ival = 512, jval = 1024, kval = 4096;
    // unsigned buffsize;
    // unsigned swt = get_value();
    // switch (swt)
    // {
    // case ival:         //error constant expression
    //     /* code */
    //     break;
    
    // default:
    //     break;
    // }


    return 0;
}
