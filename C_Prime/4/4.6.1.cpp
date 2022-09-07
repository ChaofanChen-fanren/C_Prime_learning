#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int grade = 80;
    cout << ((grade < 60) ? "fail" : "pass") << endl;
    cout << (grade < 60 ? "fail" : "pass") << endl;
    // cout << (grade < 60) ? "fail" : "pass" << endl;
    // cout << grade < 60 ? "fail" : "pass" << endl;

    // << >> | & ^ generally unsigned
    cout << (1 << 2) << endl;
    cout << (4 >> 2) << endl;
    cout << (1 & 2) << endl;
    cout << (1 | 2) << endl;
    cout << (1 ^ 2) << endl;

    unsigned long quiz = 0;
    quiz |= (1UL << 27);
    quiz &= ~(1UL << 27);
    bool status = quiz & (1UL << 27);

    //sizeof() sizeof
    int str, *p;
    cout << sizeof(int) << endl;
    cout << sizeof(p) << endl;
    cout << sizeof(*p) << endl;
    cout << sizeof(str) << endl;

    int num[10];
    cout << "size :" << sizeof(num) / sizeof(*num) << endl;

    return 0;
}
