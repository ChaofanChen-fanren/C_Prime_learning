#include <iostream>
using namespace std;
int main()
{
    // hang else
    int grade = 0;
    cin>>grade;
    if(grade % 10 >= 3)
        if(grade % 10 > 7)
            cout << ">= 70";
    else
        cout << "< 30";

    // |
    // 
    if(grade % 10 >= 3)
        if(grade % 10 > 7)
            cout << ">= 70";
        else
            cout << "< 30";
    

    if(grade % 10 >= 3){
        if(grade % 10 > 7)
            cout << ">= 70";
    }else
        cout << "< 30";




    return 0;
}
