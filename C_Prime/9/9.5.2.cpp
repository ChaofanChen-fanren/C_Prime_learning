#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    // string: insert() and earse()
    string s;
    s.insert(s.size(), 5, '!');
    s.erase(s.size() - 5, 5);

    // assign()
    const char* cp = "Sately,plump Back";
    s.assign(cp, 7);
    s.insert(s.size(), cp + 7);

    // insert string
    s = "some string";
    string s2 = "some other string";
    s.insert(0, s2);
    s.insert(0, s2, 0, s2.size());

    // append() and replace()
    s = "C++ Prime", s2 = s;
    s.insert(s.size(), " 4th Ed.");
    s2.append(" 4th Ed.");

    //earse and insert equal replace
    s.erase(11, 3);
    s.insert(11, "5th");

    s2.replace(11, 3, "5th");
    s.replace(11, 3, "Fifth");

    return 0;
}
