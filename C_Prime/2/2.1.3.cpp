#include <iostream>
using namespace std;
int main()
{
    cout << "ffdasfsda"
        "fdsfdsaf"
        "ffdsafsdaf"
        << endl;

    cout << '\n';
    cout << "\tHi!\n";
    
    // \ Oct \x Hex
    cout << "Hi \x4dO\115!\n";
    
    // \ only read the first three number 
    //Because of over three number don't express a character
    cout << "\1234\n";
    cout << typeid(10.).name() << endl;
    cout << typeid(10e-2).name() << endl;
    int __a;
    __a = 1;
    cout << not __a << endl;
    int _;
    //int catch-22;
    //int 1_or_2 = 1;
    double Double = 1;
    _ = 1;
    // int num = 09;
    // and
    // cout << num << endl;
}
