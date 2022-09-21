#include <iostream>
#include <algorithm>
using namespace std;
// top-level const  error
void print(const int);
void print(int);

void print(int *);
void print(int *const);

// low-level const true;
void print(int &);
void print(const int &);



//const_cast and overload function
const string &shorterString(const string &s1, const string &s2)
{
    return s1.size() <= s2.size() ? s1 : s2;
}
string &shorterString(string &s1, string &s2)
{
    auto &r = shorterString(const_cast<const string &>(s1), const_cast<const string &>(s1));
    return const_cast<string &>(r);
}

int main()
{
    
    return 0;
}
