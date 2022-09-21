//g++ 6.5.3.cpp -D NDEBUG
#include <iostream>
#include <assert.h>
using namespace std;
void print(const int ia[],size_t size)
{
#ifdef NDEBUG
    cerr << __func__ << ": array size is " << size << endl;  // __func__ : function name
    cerr << __FILE__ << endl;
    cerr << __LINE__ << endl;
    cerr << __TIME__ << endl;
    cerr << __DATE__ << endl;
#endif
}
int main()
{
    int x = 0;
    int *p = &x;
    assert(p != nullptr); //can not happen

    int arr[5] = {0};
    print(arr, 5);
    return 0;
}
