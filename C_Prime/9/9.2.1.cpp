#include <vector>
#include <iostream>
using namespace std;
int main()
{
    //iterator range [begin end)
    vector<int> v;
    vector<int>::iterator iter = v.begin();
    auto begin = v.begin();
    auto end = v.end();

    while(begin != end){
        cout << *begin << endl;
        begin++;
    }

    auto it1 = v.begin();
    auto it2 = v.end();
    auto it5 = v.cbegin();  // ector<int>::const_iterator;
    auto it3 = v.rbegin();  // vector<int>::reverse_iterator
    auto it4 = v.crbegin(); // vector<int>::const_reverse_iterator

    return 0;
}
