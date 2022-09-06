#include <iostream>
using namespace std;

int main()
{
    //The dimension must be a constant expression
    int arr[5] = {1, 2, 3}; //{1,2,3,0,0};
    int *p[10];
    string str[10];
    // error
    // unsigned size = 10;
    // int a[size] = {1,2};

    // don't copy assignment
    //int arr1[5] = arr;

    int arr1[10];
    // understand array
    int *ptr[10];
    int(*ptr1)[10];
    // int &arrRef[10] = /**?**/ don't exist reference array
    int(&arrRef)[10] = arr1;

    return 0;
}
