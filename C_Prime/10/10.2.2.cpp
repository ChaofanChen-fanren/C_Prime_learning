#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;
int main()
{
    vector<int> v1(10, 1), v2(10, 1);
    fill_n(v1.begin(),v1.size(), 2);
    fill_n(v2.begin(),v2.size(), 2);

    cout << equal(v1.begin(), v1.end(), v2.begin()) << endl;

    // back_inserter
    vector<int> vec;
    auto it = back_inserter(vec);
    *it = 42;

    // back_inserter and fill_n
    fill_n(back_inserter(vec), 10,
           0);  // don't worry overflow size because of insert

    for (auto val : vec) {
        cout << val << " ";
    }
    cout << endl;

    // copy()
    int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int a2[sizeof(ia) / sizeof(*ia)];
    auto ret = copy(begin(ia), end(ia), a2);

    // replace() and replace_copy()
    vector<int> re_copy;
    replace(v1.begin(), v1.end(), 2, 42);
    replace_copy(v2.begin(), v2.end(), back_inserter(re_copy), 2, 42);

    for (auto val : re_copy) {
        cout << val << " ";
    }
    cout << endl;


    return 0;
}
