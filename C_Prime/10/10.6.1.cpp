#include <list>
#include <iostream>
#include <algorithm>
#include <forward_list>
using namespace std;
int main()
{
    // list and forward_list

    // merge(lst2) merge(lst2,comp)
    list<int> lst = {1, 2, 3}, lst2 = {5, 6, 7};
    lst.merge(lst2);
    for (auto val : lst) {
        cout << val << " ";
    }
    cout << endl;

    // lst.remove(val) and lst.remove_if(pred)
    // lst.reverse()
    // lst.sort()
    // lst.sort(comp)
    // lst.unique()
    // lst.unique(pred)

    // lst.splice(args) and lst.splice_after(args)
    
    return 0;
}
