#include <algorithm>
#include <iostream>
#include <list>
#include <vector>
using namespace std;
int main()
{
    // back() front() at() []
    vector<int> v = {1, 2, 3};
    cout << v.back();
    cout << v.front();
    cout << v.at(0);
    auto& r   = v.at(0);  // should be add &;  r : int&
    auto  val = v.at(0);  // val = v[0]; val : int

    // pop_bacl() pop_front() erase()
    list<int> lst = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    auto it = lst.begin();
    while (it != lst.end()) {  // erase will make iterator invaild so end()
                               // could be updata iterator;
        if (*it & 1) {
            it = lst.erase(it);
        }
        else {
            ++it;
        }
    }
    lst.clear();
    lst.erase(lst.begin(), lst.end());
}
