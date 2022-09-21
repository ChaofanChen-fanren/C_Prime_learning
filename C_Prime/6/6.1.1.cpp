#include <iostream>
#include <vector>
using namespace std;
// int f(int v1,v1) //error

size_t count_calls()
{
    static size_t ctr = 0;
    return ++ctr;
}
int main()
{
    for (size_t i = 0; i != 10;++i){
        cout << count_calls() << endl;
    }
    return 0;
}
