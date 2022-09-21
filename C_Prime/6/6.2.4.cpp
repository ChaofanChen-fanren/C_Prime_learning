#include <iostream>
#include <algorithm>
using namespace std;
// void print(const int *);
// void print(const int[]);
// void print(const int[10]);


//be point
// use begin() end()
void print(const int *beg,const int *end)
{
    while(beg != end)
        cout << *beg++ << endl;
}
void print(const int ia[],size_t size)
{
    for (size_t i = 0; i != size;i++){
        cout << ia[i] << endl;
    }
}

//by reference 
void printRef(int (&arr)[10])
{
    for(auto elem : arr)
    {
        cout << elem << endl;
    }
}


// multidmensional array
//void printMulArr(int matrix[10],int rowsize) //error
//void printMulArr(int (*matrix)[10],int rowsize)
void printMulArr(int matrix[][10],int rowsize)
{
    for (size_t i = 0; i < rowsize;i++){
        for (size_t j = 0; j < 10;j++){
            cout << matrix[i][j]<<" ";
        }
        cout << endl;
    }
}

int main()
{
    int j[2] = {0, 1};
    print(begin(j), end(j));
    print(j, end(j) - begin(j));

    int arr[10] = {1};
    printRef(arr);

    int matrix[2][10] = {1};
    printMulArr(matrix, 2);
    return 0;
}
