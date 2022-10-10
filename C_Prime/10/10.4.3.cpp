#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    // reverse_iterator
    string line = "Hello,haha,World,Git,git";
    // cout first word
    auto comma = find(line.cbegin(), line.cend(), ',');
    cout << string(line.cbegin(), comma) << endl;

    // cout last word
    auto rcomma = find(line.crbegin(), line.crend(), ',');
    cout << string(line.crbegin(), rcomma) << endl;  // error tig
    // ture reverse_iterator convert to iterator  base()
    cout << string(rcomma.base(), line.cend()) << endl;

    return 0;
}
