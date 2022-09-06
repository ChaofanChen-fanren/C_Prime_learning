#include <iostream>
using namespace std;
int main()
{
    const string s = "asdfdas";
    for(auto &c : s){   //c : const &char
        cout << c << endl;
    }
    return 0;
}
