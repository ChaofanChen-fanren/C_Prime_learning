#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v;
    int val;
    while (cin >> val){
        v.push_back(val);
    }

    //1
    int i = 0;
    while(i < v.size()){
        cout << v[i] << " ";
        i++;
    }
    cout << endl;
    //2
    for (int i = 0; i < v.size();i++){
        cout << v[i] << " ";
    }
    cout << endl;
    //2
    for(auto val : v){
        cout << val << " ";
    }
    cout << endl;

    i = 0;
    do
    {
        cout << v[i] << " ";
        i++;
    } while (i < v.size());
    cout << endl;
    return 0;
}
