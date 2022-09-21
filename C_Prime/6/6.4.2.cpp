#include <iostream>
using namespace std;
string read();
void print(const string &);
void print(double);
void fooBar(int ival)
{
    bool read = false;
   //string s = read(); //error  read is a variable
    void print(int);
    print("Value");
    print(ival);
    print(3.14);    // print(const string &),print(double) be overwritten for print(int) of fooBar function

}
int main()
{
    
    return 0;
}
