#include <iostream>
#include <vector>
using namespace std;
// no return value
void swap(int &v1, int &v2)
{
    int temp = v1;
    v1 = v2;
    v2 = temp;
}
// have return value
string::size_type stringSize(const string &str)
{
    return str.size();
}

vector<string> process()
{
    return {"ok", "yes"};
}
int main()
{
    vector<string> ret = process();
    return 0;
}
