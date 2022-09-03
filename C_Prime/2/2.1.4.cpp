#include <iostream>
using namespace std;
int reused = 42; // global scope
int main()
{
    int unique = 0; //block scope
    cout << reused << " " << unique << endl;
    int reused = 0; // new block scope reused,and coverage global scope reused;
    cout << reused << " " << unique << endl;
    //display access to gobal reused
    cout << ::reused << " " << unique << endl;

    int j = reused;
    cout << j << endl;

    int i = 100, sum = 0;
    for (int i = 0; i != 10;i++){
        sum += i;
    }
    cout << i << " " << sum << endl;
    return 0;
}
