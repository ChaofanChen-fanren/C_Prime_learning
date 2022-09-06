#include <cctype>
#include <iostream>
using namespace std;

int main()
{
    cout << isalnum('a') << endl;                     // if character or digit
    cout << isalpha('a') << endl;                     // if character
    cout << isdigit('1') << endl;                     // if digit

    cout << toupper('a') << endl; // Turn it to uppercase
    cout << tolower('A') << endl; // Turn it to lowercase
    cout << islower('A') << endl;
    cout << isupper('a') << endl;

    string s("fasdfdsAAA");
    for (auto &c : s)  //reference 
    {
        c = toupper(c);
    }
    cout << s << endl;
    return 0;
}
