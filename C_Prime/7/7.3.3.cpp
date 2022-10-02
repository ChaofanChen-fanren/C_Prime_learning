#include <iostream>
#include <vector>
using namespace std;
class Screen; // Declaration of a class


class Screen{
    friend class Window_mgr;
public:
    typedef std::string::size_type pos;
    Screen(pos ht,pos wd,char c = ' '):height(ht),width(wd),contents(ht*wd,c){}
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;

};

class Window_mgr{
public:
    using ScreenIndex = std::vector<Screen>::size_type;
    void clear(ScreenIndex);
private:
    std::vector<Screen> screen{Screen(24, 80, ' ')};
};

void Window_mgr::clear(ScreenIndex i)
{
    Screen &s = screen[i];
    s.contents = string(s.height * s.width, ' ');
}
int main()
{
    return 0;
}
