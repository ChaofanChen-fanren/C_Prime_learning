#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    const char* cp = "Hello World!!!";
    char        noNull[] = {'H', 'e'};  // don't have end of string flag '\0'
    string      s1(cp);
    string      s2(noNull, 2);
    string      s3(noNull);  // error
    string      s4(cp + 6, 5);
    string      s5(s1, 6, 5);
    string      s6(s1, 6);
    string      s7(s1, 6, 20);
    string      s8(s1, 16);

    // substr()
    string s("Hello World");
    string s9 = s.substr(0, 5);
    string s10 = s.substr(6);
    string s11 = s.substr(6, 11);
    string s12 = s.substr(12);
}
