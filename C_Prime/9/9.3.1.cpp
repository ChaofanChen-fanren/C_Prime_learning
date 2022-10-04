#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <array>
using namespace std;
class Person
{
public:
    string name;
    string number;
    Person(){
        name = "";
        number = "";
    }
    Person(string name, string number) : name(name), number(number){};
};

int main()
{
    //push_back() except array forward_list
    vector<int> v;
    v.push_back(1);

    //push_back list forward_list deque
    list<int> l;
    for (size_t ix = 0; ix != 0;ix++){
        l.push_front(ix);
    }


    //insert(iter,item)
    vector<string> svec;
    list<string> slist;
    slist.insert(slist.begin(), "Hello");
    svec.insert(svec.begin(), "Hello");
    //insert range
    svec.insert(svec.end(), 10, "Anna");
    vector<string> vs = {"quasi","simba","frollo","scar"};
    slist.insert(slist.begin(),vs.end()-2,vs.end());
    slist.insert(slist.begin(),vs.end()-2,vs.end());

    //insert return insert element next point
    list<string> lst;
    auto iter = lst.begin();

    // emplace_front() emplace() emplace_back();
    vector<Person> vp;
    vp.emplace_back("aa", "12345");
    vp.emplace_back(); //default constructor
    vp.push_back(Person("A", "124"));
    
    return 0;
}
