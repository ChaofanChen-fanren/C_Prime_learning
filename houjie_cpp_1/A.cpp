#include <iostream>
using namespace std;
class A
{
public:
    static A &getInstance();
    void setup(){
        cout << "Singleton A" << endl;
    }

private:
    A(){
        cout << "A" << endl;
    }
    A(const A &rhs);
};

A& A::getInstance()
{
    static A a;
    return a;
}
int main()
{
    A::getInstance().setup();
    return 0;
}
