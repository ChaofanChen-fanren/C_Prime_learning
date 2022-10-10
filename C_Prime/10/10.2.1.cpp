#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <numeric>
using namespace std;
int main()
{
    vector<int> vec(10, 1);
    // read only algorithm
    int sum = accumulate(vec.cbegin(), vec.cend(), 0);

    vector<string> v(10, "c");
    string str = accumulate(v.cbegin(), v.cend(), string(""));

    cout << sum << endl;
    cout << str << endl;

}
