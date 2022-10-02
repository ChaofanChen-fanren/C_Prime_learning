#include <iostream>
#include <vector>
using namespace std;
class ConstRef{
public:
    ConstRef(int ii);
private:
    int i;
    const int ci;
    int &ri;
};
ConstRef::ConstRef(int ii):i(ii),ci(ii),ri(ii)
{
}
// ConstRef::ConstRef(int ii)
// {
//     i = ii;
//     ci = i;//error
//     ri = i;//error
// }
int main()
{
    return 0;
}
