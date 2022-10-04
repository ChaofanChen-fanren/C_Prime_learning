#include <iostream>
#include <vector>
using namespace std;
int main()
{
    // capacity() and reserve()
    std::vector<int> ivec;
    std::cout << "size : " << ivec.size() << std::endl;
    std::cout << "capacity: " << ivec.capacity() << std::endl;


    for (vector<int>::size_type ix = 0; ix != 24; ix++) {
        ivec.push_back(ix);
    }
    // size:24
    std::cout << "size : " << ivec.size() << std::endl;
    std::cout << "capacity: " << ivec.capacity() << std::endl;

    // reserve(num) to set capacity >= max(num,size);
    ivec.reserve(50);
    std::cout << "size : " << ivec.size() << std::endl;
    std::cout << "capacity: " << ivec.capacity() << std::endl;
}
