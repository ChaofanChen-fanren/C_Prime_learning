#include <iostream>
#include <algorithm>
#include <istream>
#include <iterator>

int main()
{
    std::istream_iterator<int> in_int(std::cin);
    std::istream_iterator<int> eof;

    while (in_int != eof) {
        std::cout << (*in_int++) << std::endl;
    }
    return 0;
}
