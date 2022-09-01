#include <iostream>
int main()
{
    // int sum = 0, val = 50;
    // while(val <= 100){
    //     sum += val;
    //     ++val;
    // }
    // std::cout << "Sum of 50 to 100 inclusive is "
    //           << sum << std::endl;

    // int sum = 0;
    // //Sum of 0 to 10 inclusive
    // for (int val = 0; val <= 10;val++){
    //     sum += val;
    // }
    // std::cout << "Sum of 0 to 10 inclusive is "
    //           << sum << std::endl;

    int sum = 0, value = 0;
    // read data from stdin until EOF
    while (std::cin >> value)
    {
        sum += value;
    }
    std::cout << "Sum is:" << sum << std::endl;

    return 0;
}
