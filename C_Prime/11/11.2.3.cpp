#include <algorithm>
#include <cstddef>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
int main()
{
    // pair initialization
    pair<string, int> word = {"a", 10};
    pair<string, int> word1("b", 10);
    pair<string, int> word2 = make_pair("a", 10);
    
    // first second
    cout << word.first << " " << word.second << endl;
    
    


    return 0;
}
