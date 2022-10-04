#include <iostream>
#include <string.h>
#include <string>
using namespace std;
int main()
{
    // number convert to string  to_string() stod()
    int i = 42;
    string s = to_string(i);
    double d = stod(s);

    string s2 = "p1 = 3.14";
    d         = stod(s2.substr(s2.find_first_of("+-.0123456789")));


    string s3 = "10";
    cout << stoi(s3, 0, 2) << endl;
    return 0;
}
