#include <iostream>
#include <algorithm>
#include <istream>
#include <iterator>
#include <vector>
using namespace std;
int main()
{
    vector<int> v = {42, 42, 42, 42, 42, 42};
    int ia[] = {42, 42, 42, 42, 42, 42};
    int* result = find(begin(ia) + 3, begin(ia) + 4, 42);

    vector<int>::iterator res = find(v.begin(), v.end(), 42);
    cout << *result << endl;
    cout << *res << endl;
    return 0;
}
