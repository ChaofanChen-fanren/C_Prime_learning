#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    string file = "./8.2.1.cpp";
    ofstream out1(file, ofstream::out); //ofstream out1(file, ofstream::out | ofstream::trunc);
    ofstream out2(file, ofstream::out | ofstream::app);
    out1.close();
    out2.close();

    return 0;
}
