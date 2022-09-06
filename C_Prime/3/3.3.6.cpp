#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    // c string
    char cstr[] = {'C', '+', '+'};
    char cstr1[100] = "C++"; //{'C', '+', '+','\0'}
    char cstr2[] = "C++ best";

    // c string function
    // strlen(p1)
    // cout << strlen(cstr) << endl;//error ,c string must be end of '\0';
    cout << strlen(cstr1) << endl;
    // strcmp(p1,p2)
    cout << strcmp(cstr1, cstr2) << endl;
    // strcat(p1,p2) p1 <-- p2
    cout << strcat(cstr1, cstr2) << endl;
    // strcpy(p1,p2) p1 <-- p2
    cout << strcpy(cstr1, cstr2) << endl;

    string str = "C++";
    string str1 = "C++ best";
    // string operator < 
    cout << (str < str1) << endl;

    // but c string don't operator < so (cpstr < cpstr1) is compare point adress
    //cout << (cstr < str1) << endl;

    return 0;
}
