#include <cstdio>
#include <iostream>
#include <list>
using namespace std;
int main()
{
    // chang size resize()
    list<int> ilist(10, 42);
    ilist.resize(15);
    ilist.resize(25, -1);
    ilist.resize(5);
    
}
