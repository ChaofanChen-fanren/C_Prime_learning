#include <bits/stdc++.h>
#include <fstream>
using namespace std;
int main()
{
    fstream file;
    file.open("./1325.txt");
    string a, b, c;
    double sum = 0;
    while (file >> a >> b >> c) {
        int num = stoi(b);
        double f = 0;
        if (c == "半价")
            f = 0.5;
        else {
            string temp = c.substr(0, c.find("折"));
            if (temp.size() == 1)
                temp += '0';
            cout << temp << endl;

            f = (double)stoi(temp) / 100;
        }
        sum += f * num;
    }
    cout << sum << endl;
    // 5200
    return 0;
}
