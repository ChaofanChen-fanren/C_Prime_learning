#include <iostream>
using namespace std;
//inline function
inline const string &
shorterString(const string &s1, const string &s2)
{
    return s1.size() <= s2.size() ? s1 : s2;
}

//constexpr function
constexpr int new_sz()
{
    return 42;
}
int main()
{
    int arr[new_sz()]; //new_sz is const expression
    return 0;
}
