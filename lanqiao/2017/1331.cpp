#include <bits/stdc++.h>
#include <fstream>
#include <string>
#include <unordered_map>
using namespace std;
int main()
{
    string s;
    unordered_map<string, int> ma;
    unordered_map<string, int> mb;
    unordered_map<string, int> mc;
    ifstream fa, fb, fc;
    fa.open("a.txt", ios::in);
    fb.open("b.txt", ios::in);
    fc.open("c.txt", ios::in);

    while (fa >> s) {
        // if(ma[s]){
        //     cout << "impossible" << endl;
        //     return 0;
        // }
        ma[s]++;
    }
    while (fb >> s) {
        // if (ma[s]) {
        //     cout << "impossible" << endl;
        //     return 0;
        // }
        mb[s]++;
    }
    while (fc >> s) {
        mc[s]++;
    }
    fa.close();
    fb.close();
    fc.close();

    int res = 0;
    for (auto x : ma) {
        if (mb[x.first] && !mc[x.first])
            res++;
    }
    cout << res << endl;

    return 0;
}
