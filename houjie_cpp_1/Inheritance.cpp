#include <iostream>
#include <vector>
int main()
{
    //A 是父类 B是复合类  C继承A并且复合B
    using namespace std;
    class A{
    public:
        A(){
            cout << "this is father classer ctor" << endl;
        }
        ~A(){
            cout << "this is father classer dtor" << endl;
        }
    private:
        int a;
    };

    class B{
    public:
        B(){
            cout << "Composition class ctor" << endl;
        }
        ~B(){
            cout << "Composition class dtor" << endl;
        }
    private:
        int b;
    };

    class C:A{
    public:
        C(){
            cout << "child class ctor" << endl;
        }
        ~C(){
            cout << "child class dtor" << endl;
        }
    private:
        int c;
        B b;
    };

    C c;
    return 0;
}
