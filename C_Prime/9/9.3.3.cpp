#include <algorithm>
#include <forward_list>
#include <iostream>
using namespace std;
int main()
{
    // forward_list
    forward_list<int> flst = {0, 1, 2, 3, 4, 5, 6};

    auto prev = flst.before_begin();
    auto curr = flst.begin();
    while (curr != flst.end()) {
        if (*curr % 2)
            curr = flst.erase_after(prev);
        else {
            prev = curr;
            ++curr;
        }
    }
}
