#include <iostream>
using namespace std;
int main()
{
    int i = 42;
    int *p1 = &i;
    *p1 = *p1 * *p1;

    //long *p2 = &i;
    return 0;
}
