#include <iostream>
#include <vector>
using namespace std;
class Bar{
public:
private:
    static Bar mem1;
    Bar *mem2;
    //Bar mem3; // error  An incomplete type be used for static 、 point and reference

};


class Screen{
public:
    // bkground static member;
    Screen &clear(char = bkground);
private:
    static const char bkground;
};
int main()
{
    return 0;
}
