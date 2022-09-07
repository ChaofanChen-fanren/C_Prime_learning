#include <iostream>
using namespace std;

int main()
{
    int arr[3] = {0, 0, 0};
    int *p = arr;
    cout << *p + 1 << endl; // * higher priority than +
    cout << *(p + 1) << endl;

    // mostly operator haven't evaluate the order
    int i = 0;
    cout << i << " " << ++i << endl;
    return 0;
}
