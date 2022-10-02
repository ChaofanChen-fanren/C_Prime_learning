#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
void process_input(istream& cin)
{
    return;
}
int main()
{
    ofstream out1, out2;
    /**
     * 1. Cannot be assigned
     * 2. Cannot be funtional paramter
     * 3. Cannot be copyed;
     */
    //out1 = out2;
    //ofstream print(ofstream);
    //out2 = print(out1)

    //condition state
    auto old_state = cin.rdstate(); //save previous condition state
    cin.clear();                    // cin can be vaild
    process_input(cin);           // paramter of funtion should be reference
    cin.setstate(old_state);     // convert to old_state
    cin.clear(cin.rdstate() & ~cin.failbit & ~cin.badbit); // reset failbet and badbit
}
