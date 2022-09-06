#include <iostream>
#include <iterator>
using namespace std;

int main()
{
    // multidimensional array initialization
    int arr[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    int arr1[2][3] = {1, 2, 3, 4, 5, 6};

    // for access
    for(const auto &row : arr){  // must be write reference because arr is a point
        for (auto col : row){
            cout << col << " ";
        }
        cout << endl;
    }

    for (auto p = begin(arr); p != end(arr);p++){
        for (auto q = begin(*p); q != end(*p);q++){
            cout << *q << " ";
        }
        cout << endl;
    }

    return 0;
}
