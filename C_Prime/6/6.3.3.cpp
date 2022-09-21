#include <iostream>
using namespace std;
// return array point
// eg1
typedef int arrT[10];
//using arrT = int[10];
arrT *func(int i);

//eg2
int (*func(int i))[10];

//eg3
auto func(int i) -> int (*)[10];


//eg4
int odd[] = {1, 3, 5, 7, 9}; //odd ->int[5]

decltype(odd) *arrPtr(int i); // int (*)[5];
int main()
{
    
    return 0;
}
