#include <algorithm>
#include <cstddef>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
int main()
{
    // map and set initialization
    vector<int> ivec;
    for (vector<int>::size_type i = 0; i != 10; i++) {
        ivec.push_back(i);
        ivec.push_back(i);
    }

    set<int> iset(ivec.begin(), ivec.end());
    multiset<int> miset(ivec.begin(), ivec.end());
    cout << iset.size() << endl;
    cout << miset.size() << endl;

    
    return 0;
}
