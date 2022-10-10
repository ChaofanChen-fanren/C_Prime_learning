#include <cstddef>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// value capatrue
void fun1()
{
    size_t v1 = 42;
    auto f = [v1] { return v1; }; //create to capture
    v1 = 0;
    auto j = f();
    cout << j << endl;  // j = 42;
}
//reference capatrue
void fun2()
{
    size_t v1 = 42;
    auto f = [&v1] { return v1; };
    v1 = 0;
    auto j = f();
    cout << j << endl;  // j = 0;
}

// cout by reference capatrue
// for_each(word.begin(), word.end(), [&os, c](const string& s) { os << s << c; });

// should be add mutable when change value
void fun3()
{
    size_t v1 = 42;
    auto f = [v1]() mutable { return ++v1; };
    v1 = 0;
    auto j = f();  // j = 43;
}
int main()
{
    // [&,identifier_list] implicit reference capatrue
    // [=,identifier_list] implicit value capatrue


    // lambda return
    vector<int> v(10, -1);
    // transform(v.begin(), v.end(), v.begin(),
    //           [](int i) { return i < 0 ? -i : i; });
    transform(v.begin(), v.end(), v.begin(), [](int i) {
        if (i < 0)
            return -i;
        else
            return i;
    });  // error don't infer to return type for C Prime but now can be infered

    for_each(v.begin(), v.end(), [](const int& val) { cout << val << " "; });
    cout << endl;

    return 0;
}
