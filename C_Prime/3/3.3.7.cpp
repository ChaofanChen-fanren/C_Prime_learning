#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

int main()
{
    // string(c string)
    string str("C++ best");
    cout << str.c_str() << endl;

    // vector(begin(arr),end(arr))
    int arr[10] = {0};
    vector<int> v(begin(arr), end(arr));
    
    return 0;
}
