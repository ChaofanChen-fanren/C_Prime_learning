#include <iostream>
using namespace std;
void error_msg(initializer_list<string> il)
{
    for (auto beg = il.begin(); beg != il.end();beg++){
        cout << *beg << " ";
    }
    cout << endl;
}
int main()
{
    error_msg({"is", "ok", "error", "Yes"});
    return 0;
}
