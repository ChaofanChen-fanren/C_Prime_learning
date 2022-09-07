#include <iostream>
#include <vector>

using namespace std;

int main()
{
    //conversion
    
    //static_cast<typename>(variable name)
    double d;
    void *p = &d;
    double *dp = static_cast<double *>(p);

    //error    At the bottom of the const
    // const void *sp = &d;
    // double *dp = static_cast<double>(p);
    

    //const_cast<typename>(variable name)
    const double *sp = &d;
    double *sdp = const_cast<double *>(sp);


    //reinterpret_cast<typename>(variable name)
    int *ip;
    char *pc = reinterpret_cast<char *>(ip);
    string str(pc); // likely to exception !!!

    int i = 0;
    char c = (char)i;

    return 0;
}
