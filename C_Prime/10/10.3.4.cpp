#include <iostream>
#include <algorithm>
#include <ostream>
#include <string>
#include <vector>
#include <functional>
using namespace std;
using namespace std::placeholders; //_1
bool check_size(const string& s, string::size_type sz)
{
    return s.size() >= sz;
}
ostream& print(ostream& os, const string& s, char c)
{
    return os << s << c;
}
int main()
{
    // auto newCallable = bind(callble,arg_list);
    string s = "hello world";
    auto check6 = bind(check_size, _1, 6);
    cout << check6(s) << endl;


    // auto g = bind(f,a,b,_2,c,_1);
    // g(_1,_2) -> f(a,b,_2,c,_1)

    
    // bind reference
    vector<string> words(10,"sss");
    for_each(words.begin(),words.end(),bind(print,ref(cout),_1,' '));
    return 0;
}
