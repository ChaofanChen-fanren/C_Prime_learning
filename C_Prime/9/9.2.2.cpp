#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <array>
using namespace std;
int main()
{
    // init
    list<string> authors = {"M", "S", "A"};
    vector<const char *> article = {"a", "an", "the"};

    //deque<string> authList(authors); //error
    //vector<string> words(article);//error
    vector<string> words(article.begin(), article.end());//const char * convert to string

    //
    vector<int> ivec(10, -1);
    list<int> ls(10, 9); // {9,9,9,9,9,9,9,9,9,9}

    //array
    array<int, 42>::size_type i;
    array<int, 10> ia1;
    array<int, 10> ia2 = {0,1,2,3,4,5,6,7,8,9};
    array<int, 10> ia3 = {42}; // {42,0,0,0,0,0,0,0,0,0};
    //int a[10] = ia1;//error

    array<int, 10> copy = ia2;

    return 0;
}
