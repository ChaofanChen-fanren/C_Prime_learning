#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    string s = "abcdefg";

    vector<int>::iterator it = v.begin(); //iterator
    string::iterator sit = s.begin();//iterator
    cout << *sit<< endl;
    cout << *it << endl;

    vector<int>::const_iterator iter = v.cbegin(); //const_iterator
    string::const_iterator siter = s.cbegin();//const_iterator
    cout << *siter<< endl;
    cout << *iter << endl;

    vector<string> vs = {"aaa", "bbb"};
    vector<string>::iterator vsit = vs.begin();
    // auto vsit = vs.begin();
    cout << (*vsit).size() << endl; // must write ()
    cout << vsit->size() << endl;
    return 0;
}
