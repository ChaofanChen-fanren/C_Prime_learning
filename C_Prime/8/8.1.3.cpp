#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    //Flush the buffer
    cout << "h1!" << endl;  // add '/n'
    cout << "hi!" << flush; // don't addition
    cout << "hi!" << ends;  // add ' '

    //set each ouput operation to flushing the buffer
    cout << unitbuf;
    //set back
    cout << nounitbuf;
    
    //associate ouputs with input ostream
    cin.tie(&cout); //associate to cout  cout flush the buffer while cin reading data
    ostream *old_tie = cin.tie(nullptr); //return old associated ostream point
    cin.tie(&cerr);
    cin.tie(old_tie);

    return 0;
}
