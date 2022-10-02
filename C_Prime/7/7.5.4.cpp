#include <iostream>
#include <vector>
using namespace std;

class Sales_data{
public:
    //constructor function
    Sales_data() = default;
    explicit Sales_data(const std::string &s):bookNo(s){}
    Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p * n){}
    explicit Sales_data(std::istream &);
private:
    //member data
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

int main()
{
    string null_book = "fa";
    //Sales_data item = null_book; //error

    Sales_data item1(null_book);

    static_cast<Sales_data>(null_book);

    return 0;
}
