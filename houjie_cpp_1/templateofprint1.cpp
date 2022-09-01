#include <iostream>
using namespace std;
template<class T>
void printarg(T t) //each of parameter print
{
    cout << t << endl;
}

template<class ...Args>
void expand(Args... args)
{
    //comma expansion
    int arr[] = {(printarg(args), 0)...};
    //int arr[] = {(printarg(arg1),0), (printarg(arg2),0), (printarg(arg3),0),  etc... }
}

int main()
{
    expand(1,2,3,4);
    return 0;
}
