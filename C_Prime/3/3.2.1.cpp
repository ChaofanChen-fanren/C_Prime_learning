#include <iostream>
using namespace std;

int main()
{
    //string initialization
    string s1;
    string s2 = s1;//copy initialization 
    string s3 = "hiya";  
    string s4(10, 'c'); //s4 = ccccc ccccc
    string s5(s4);
    string s6("value");//direct initialization

    //temporary objects
    string s7 = string(10, 'c'); // copy initialization


    //string operation
    
    //Read and write strings
    string s;
    cin >> s;//brank
    getline(cin, s); // line break
    cout << s << endl;

    // size() return type : string::size_type(unsigned)
    cout << s.size() << endl;
    
    // +=  +
    s1 += s2; // s1 = s1 + s2
    s3 = s1 + s2;
    //s2 = "f" + "f"; //error " "(String literal) must have string in the left or right
    
}
