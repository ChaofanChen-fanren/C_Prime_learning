#include <iostream>
using namespace std;
bool lengthCompare(const string &s1, const string &s2)
{
    return s1.size() >= s2.size();
}
bool (*pf)(const string &, const string &);

void useBigger(const string &s1, const string &s2, bool (*bf)(const string &, const string &)); 
void useBigger(const string &s1, const string &s2, bool bf(const string &, const string &));


// Func and Func2 are function type
typedef bool Func(const string &, const string &);
typedef decltype(lengthCompare) Func2;

//funcP and funcP2 are function point type
typedef bool (*FuncP)(const string &, const string &);
typedef decltype(lengthCompare) *Func2;

using F = int(int *, int);
using PF = int (*)(int *, int);

PF f1(int); //int (*f1(int))(int *, int);
auto f1(int) -> int (*)(int *, int);

// auto and decltype be used in function point;
string::size_type sumLength(const string &, const string &);
string::size_type largerLength(const string &, const string &);
decltype(sumLength) *getFcnt(const string &);



int main()
{
    pf = lengthCompare;
    bool flag = pf("hello", "goodbye");
    bool flag1 = (*pf)("hello", "goodbye");

    
    return 0;
}
