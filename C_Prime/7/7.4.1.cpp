#include <iostream>
#include <vector>
using namespace std;

int height = 5;
class Screen
{
    friend class Window_mgr;
public:
    typedef std::string::size_type pos;
    Screen(pos ht,pos wd,char c = ' '):height(ht),width(wd),contents(ht*wd,c){}

    void dummu_fcn(pos height){
        cursor = width * ::height; // global variable height;
        cout << ::height << endl;
    }

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
};
int main()
{
    Screen::pos ht = 24, wd = 80;
    Screen scr(ht, wd, ' ');
    scr.dummu_fcn(14);
    return 0;
}
