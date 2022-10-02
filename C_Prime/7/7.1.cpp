#include <iostream>
#include <vector>
using namespace std;

class Sales_data{
    //friend 
    //The friend declaration only declares the access relation,does not declare the function
    friend Sales_data add(const Sales_data &, const Sales_data &);
    friend std::ostream &print(std::ostream &, const Sales_data &);
    friend std::istream &read(std::istream &, Sales_data &);

public:
    //constructor function
    Sales_data() = default;
    Sales_data(const std::string &s):bookNo(s){}
    Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p * n){}
    Sales_data(std::istream &);

    //member function
    std::string isbn() const { return bookNo; } // const member function
    Sales_data &combine(const Sales_data &);
    double avg_price() const; // this : const Sales_data *const
private:
    //member data
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};


//Sales_data no-member function
Sales_data add(const Sales_data &, const Sales_data &);
std::ostream &print(std::ostream &, const Sales_data &);
std::istream &read(std::istream &, Sales_data &);



Sales_data& Sales_data::combine(const Sales_data&rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}
double Sales_data::avg_price() const
{
    if(units_sold)
        return revenue / units_sold;
    return 0;
}

Sales_data::Sales_data(std::istream &is)
{
    read(is, *this);
}

istream & read(istream &is,Sales_data &item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}


ostream &print(ostream &os,const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " "
       << item.revenue << " " << item.avg_price();
    return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}


int main()
{
    
}
