#include <iostream>
#include <typeinfo>
using namespace std;

int main()
{
    // auto must be initialize
    auto x = 3;
    auto y{42};

    // auto must be derived to the same type
    auto x1{1}, x2{2};
    
    //if the initialization expression is a reference or
    //const , the reference or const is removed
    int y1 = 42, &y2{y1};
    auto y3{y2};
    cout << typeid(y3).name() << endl;

    // if auto keyword has an &,reference or const don't be removed
    int a = 10;
    int &b = a;
    auto &d = b;// int&
    const int a2 = 10;
    auto &b2 = a2;//const int
    // cout << typeid(b2).name() << endl;

    int a7[3] = {1, 2, 3};
    auto b3 = a7;
    cout << typeid(b3).name() << endl;//is a point of int
    auto &b7 = a7;
    cout << typeid(b7).name() << endl;
}
