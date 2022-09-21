#include <iostream>
using namespace std;
void screen(int row, int col, char c = '#');


void screen(int row, int col, char c)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col;j++){
            cout << c << " ";
        }
        cout << endl;
    }
}


// Default initial value is varible function
int wd = 3;
char bef = '-';
int hd(){
    return 4;
}
void screenf(int row = wd,int col = hd(),char c = bef)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col;j++){
            cout << c << " ";
        }
        cout << endl;
    }
}
int main()
{

    screen(2, 2);
    screenf();
    return 0;
}
