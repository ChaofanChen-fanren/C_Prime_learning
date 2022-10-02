#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    string file = "./8.2.1.cpp";
    //1 init
    ifstream in(file);
    string buffer;
    while (in>>buffer) //read one line
    { 
        cout << buffer << endl;
    }
    // 2 init
    ofstream out;
    out.open(file + ".copy");
    if(out){
    } // check open true;

    in.close();
    in.open(file + ".copy1"); //open another file
    out.close();

    //fstream superclass is iostream
    void print(istream&);
    print(in);

    

    
    return 0;
}
