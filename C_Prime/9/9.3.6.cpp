#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    vector<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    auto iter = vi.begin();
    while (iter != vi.end()) {
        if (*iter & 1) {
            iter = vi.insert(iter, *iter);
            iter += 2;
        }
        else {
            iter = vi.erase(iter);
        }
    }

    // error : enditer will be inviald when insert() and earse;
    auto enditer = vi.end();

    iter = vi.begin();
    while (iter != enditer) {
        if (*iter & 1) {
            iter = vi.insert(iter, *iter);
            iter += 2;
        }
        else {
            iter = vi.erase(iter);
        }
    }

    

    for (auto iter = vi.begin(); iter != vi.end(); iter++) {
        cout<<*iter<<" ";
    }
    cout << endl;
    return 0;
}
