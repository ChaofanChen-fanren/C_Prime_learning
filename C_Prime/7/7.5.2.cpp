#include <iostream>
#include <vector>
using namespace std;
class Sales_data{
    friend std::istream &read(std::istream &, Sales_data &);
public:
    Sales_data(std::string s, unsigned cnt, double price) : bookNo(s), units_sold(cnt), revenue(price * cnt){}


    //The delegate constructor
    Sales_data():Sales_data("",0,0){}
    Sales_data(const std::string &s) : Sales_data(s,0,0){}
    Sales_data(std::istream &is) : Sales_data() { read(is, *this); }

private:
    //member data
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
std::istream &read(std::istream &, Sales_data &);
istream & read(istream &is,Sales_data &item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

int main()
{
    //The delegate constructor
}
