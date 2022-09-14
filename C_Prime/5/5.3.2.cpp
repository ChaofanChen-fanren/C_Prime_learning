#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v = {1, 2, 0, 4, 5};
    for (int i = 0; i < v.size();i++){
        if(v[i] == 0) continue;
        cout << v[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < v.size();i++){
        if(v[i] == 0) break;
        cout << v[i] << " ";
    }
    cout << endl;

    begin:
        int ival = 0;
        cin >> ival;
        if (ival){
            goto begin;
        }
    
    return 0;
}
