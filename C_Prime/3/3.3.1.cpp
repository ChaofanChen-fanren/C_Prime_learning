#include <iostream>
#include <vector>
using namespace std;
int main()
{
    // vector initialization
    vector<int> v1;
    vector<int> v2(v1);
    vector<int> v3 = v2;
    vector<int> v4(5,0);// {0,0,0,0,0}
    vector<int> v5{0, 0, 0, 0, 0};
    vector<int> v6 = {0, 0, 0, 0, 0};
    

    /***/
    vector<int> v7(10); // 10 0
    vector<string> v8;  // 10 ""
    // vector<int> v8 = 1;//error


    // vector function
    //size()
    cout << v7.size() << endl;
    //empty()
    cout << v7.empty() << endl;
    //push_back()
    v7.push_back(9);

    //The for loop traverses
    for(auto x : v7)
        cout << x << endl;

    for (string::size_type i = 0; i < v7.size();i++){
        cout << v7[i] << " ";
    }
    cout << endl;
    for (decltype(v7.size()) i = 0; i < v7.size();i++){
        cout << v7[i] << " ";
    }
    cout << endl;
    return 0;
}
