#include <iostream>
#include <algorithm>
#include <cstring>
#include <iterator>
#include <vector>
#include <list>
using namespace std;
int main()
{

    // back_inserter(c)
    vector<int> vc;
    auto bit = back_inserter(vc);
    for (int i = 0; i < 6; i++) {
        *bit = i;
    }
    for (auto val : vc) {
        cout << val << " ";
    }
    cout << endl;

    // front_inserter(c)
    list<int> lst = {1, 2, 3, 4}, lst2, lst3;
    // lst2 = {4,3,2,1}
    copy(lst.cbegin(), lst.cend(), front_inserter(lst2));
    // lst3 = {1,2,3,4}
    copy(lst.begin(), lst.end(), inserter(lst3, lst3.begin())); 
    

    // inserter(c,iter)
    vector<int> v;
    auto it = inserter(v, v.begin());
    *it = 42;
    // equal
    // it = v.insert(it.val);
    // ++it;
    for (auto val : v) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
