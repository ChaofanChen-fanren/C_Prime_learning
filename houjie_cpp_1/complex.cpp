#include <iostream>
using namespace std;
class complex
{
public:
    complex(double r = 0, double i = 0) : re(r), im(i){ }
    // complex(double r = 0, double i = 0){ 
    //     re = r;
    //     im = i;
    // }
    //complex() : re(0), im(0){ }
    complex& operator+=(const complex &);
    double real() const { return re; }
    double imag() const { return im; }


private:
    double re, im;
    friend complex& __doapl(complex *, const complex &);
};
inline complex& __doapl(complex * ths, const complex& r)
{
    ths->re += r.re;
    ths->im += r.im;
    return *ths;
}

inline complex& complex::operator+=(const complex& r)
{
    return __doapl(this, r);
}

ostream& operator<<(ostream& os,const complex& x)
{
    return os << '(' << x.real() << ',' << x.imag() << ')';
}

int main()
{
    complex c1(2, 1);
    complex c2(2, 1);
    c1 += c1 += c2;

    cout << c1 << endl;
    return 0;
}
