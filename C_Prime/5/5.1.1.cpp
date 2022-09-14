#include <iostream>
#include <algorithm>
using namespace std;
int getnum()
{
    return 1;
}
int main()
{
    while(int i = getnum()){
        cout << i << endl;
    }
    //i = 0; //error

    
}
