#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // must be sorted
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
    
    // iterator binary search
    auto beg = v.begin(), end = v.end();
    auto mid = v.begin() + (end - beg) / 2;

    int find_value = 2;
    while (mid != end && *mid != find_value)
    {
        if(find_value < *mid){
            end = mid;
        }else{
            beg = mid + 1;
        }
        mid = beg + (end - beg) / 2;
    }

    if(mid != v.end())
        cout<< (mid - v.begin()) <<" "<< *mid << endl;

    return 0;
}
