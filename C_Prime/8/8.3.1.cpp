#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
struct PersonInfo
{
    string name;
    vector<string> phones;
};

int main()
{
    /**name phone
     * make 12333 66666
     * amy 11222
     * kk  122 33 3333333
     * hh  12 333
     */
    //use sstringstream
    string line, word;
    vector<PersonInfo> people;
    while(getline(cin,line)){
        PersonInfo info;
        istringstream record(line);
        record >> info.name;
        while(record>>word){
            info.phones.push_back(word);
        }
        people.push_back(info);
    }
    //use ostringstream
    for(const auto &entry : people){
        ostringstream formatted, badNums;
        for(const auto &nums : entry.phones){
            if(!(valid(nums))){
                badNums << " " << nums;
            }else{
                formatted << " " << format(nums);
            }
        }
        if(badNums.str().empty()){
            cout << entry.name << " " << formatted.str() << endl;
        }else{
            cerr << "input error: " << entry.name << "invaild number(s) " << badNums.str() << endl;
        }
    }
    return 0;
}
