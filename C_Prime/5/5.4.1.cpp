#include <iostream>
#include <stdexcept>
using namespace std;
int main()
{
    //throw
    int ival, ival1;
    // cin >> ival >> ival1;
    // if (ival != ival1){
    //     throw runtime_error("ival != ival1");
    // }
    // cout << "hello error" << endl;

    //try catch

    while (cin >> ival >> ival1){
        try{
            if (ival != ival1){
                throw runtime_error("ival != ival1");
            }
        }catch (runtime_error err){
            cout << err.what()
                 << "\n Try Argin? Enter y or n" << endl;

            char c;
            cin >> c;
            if(!cin || c == 'n')
                break;
        }
    }
        return 0;
}
