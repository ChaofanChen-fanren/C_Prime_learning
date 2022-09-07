#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    vector<string> text = {"Fdaf.", "fdaf", "fdsaf."};
    for (const auto &s : text)
    {
        cout << s;
        if(s.empty() || s[s.size() - 1] == '.')
            cout << endl;
        else
            cout << " ";
    }

    int val = 5;
    if(val)
        cout << true << endl;
    else
        cout << false << endl;
    
    if(val == true) //error if(val == 1)
        cout << (val == 1) << endl;
    return 0;
}
