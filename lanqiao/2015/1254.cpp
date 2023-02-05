#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s = "aaabbbbccccc";
    vector<string> v;
    int res = 0;

    do{
        int i = 0;
        for(;i < v.size();i++){
            if (v[i].find(s) != string::npos)
                break;
        }
        if (i < v.size())
            continue;
        
        string ss = s + s;
        v.push_back(ss);
        reverse(ss.begin(), ss.end());
        v.push_back(ss);
        res++;
    }while(next_permutation(s.begin(),s.end()));

    cout << res << endl;
    return 0;
}
