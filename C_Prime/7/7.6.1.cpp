#include <iostream>
#include <vector>
using namespace std;
class Account{
public:
    void calculate() { amount += amount * interestRate; }
    static double rate() { return interestRate; }
    static void rate(double);
private:
    std::string owner;
    double amount;
    static double interestRate;
    static constexpr int period = 30;
    static double initRate();
};
void Account::rate(double newRate)
{
    interestRate = newRate;
}


double Account::interestRate = initRate();
constexpr int Account::period;

int main()
{
    double r = Account::rate();
    
}
