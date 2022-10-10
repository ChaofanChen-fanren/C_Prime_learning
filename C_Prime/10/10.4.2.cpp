#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>
using namespace std;
int main()
{
    // istream_iterator
    istream_iterator<int> in_iter(cin), eof;
    vector<int> vec(in_iter, eof);
    // accumulate(in_iter, eof, 0); sum of int
    // while (in_iter != eof) {
    //     vec.push_back(*in_iter++);
    // }
    // for (auto val : vec) {
    //     cout<<val<<" ";
    // }
    // cout << endl;

    // ostream_iterator
    ostream_iterator<int> out_iter(cout, " ");
    for (auto val : vec) {
        *out_iter++ = val;
    }
    cout << endl;
    copy(vec.begin(), vec.end(), out_iter);
    cout << endl;

    return 0;
}
