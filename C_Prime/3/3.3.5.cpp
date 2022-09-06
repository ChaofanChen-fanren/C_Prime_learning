#include <iostream>
#include <iterator>
using namespace std;

int main()
{
    //Access to an array
    // index type size_t
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    
    // for access to array
    for (size_t i = 0; i < 10;i ++){
        cout << arr[i] << " ";
    }
    cout << endl;

    // begin() end() 
    int *beg = begin(arr), *pend = end(arr);
    for (int *i = beg; i != pend;i++){
        cout << *i << " ";
    }
    cout << endl;


    // p[-2] is ok but !!!!
    int *p = &arr[2];
    cout << p[-2] << endl; //arr[0]
    return 0;
}
