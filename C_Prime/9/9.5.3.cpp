#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    // find()
    string name("AnnaBelle");
    auto   pos1 = name.find("Anna");

    string lowercase("annabelle");
    pos1 = lowercase.find("Anna");  // pos1 = npos;

    // find_first_of()
    string numbers("0123456789"), Name("r2d2");
    auto   pos = Name.find_first_of(numbers);

    string dept("03714p3");
    auto   pos2 = dept.find_first_not_of(numbers);



    // eg:find all digit position
    name = "1ffadf6334jjj9";
    pos = 0;
    while ((pos = name.find_first_of(numbers, pos)) != string::npos) {
        cout << "found number at index: " << pos;
        cout << " element is " << name[pos] << endl;
        ++pos;
    }

    // reverse search
    string river("Mississippi");
    auto   firstpos = river.find("is");
    auto   lastpos  = river.rfind("is");

    // compare()
    name.compare(1, 2, river, 1, 2);
    return 0;
}
