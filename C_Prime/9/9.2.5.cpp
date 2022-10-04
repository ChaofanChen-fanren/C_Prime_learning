#include <iostream>
#include <algorithm> //swap
#include <array>
#include <vector>
#include <list>
using namespace std;
int main()
{
    array<int, 10> a1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    array<int, 10> a2 = {0}; //init
    a1 = a2;
    a2 = {0}; // error don't assign list to array

    //swap()
    swap(a1, a2);
    a1.swap(a2);

    //assign() use only by sequence container
    list<string> names;
    vector<const char *> oldstyle;
    //names = oldstyle;//error
    names.assign(oldstyle.cbegin(), oldstyle.cend());
    names.assign(10, "GieGie");

    //size() empty() max_size()
    vector<int> v1 = {1, 3, 5, 7, 9};
    vector<int> v2 = {1, 3, 9};
    cout << (v1 == v2);
    cout << (v1 > v2);
    return 0;
}
