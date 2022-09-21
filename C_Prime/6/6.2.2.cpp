#include <iostream>
#include <vector>
using namespace std;
string::size_type find_char(const string &s,char c,string::size_type &occurs)
{
    auto ret = s.size();
    occurs = 0;
    for (decltype(ret) i = 0; i != s.size();i++){
        if(s[i] == c){
            if(ret == s.size())
                ret = i;
            ++occurs;
        }
    }
    return ret;
}
int main()
{
    string ::size_type occurs = 9;
    string str = "fdasfdsf";
    string::size_type index = find_char(str, 'f', occurs);
    cout << index << " " << occurs << endl;
    return 0;
}
