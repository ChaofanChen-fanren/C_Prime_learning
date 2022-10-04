#include <cstddef>
#include <functional>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <deque>
#include <queue>
using namespace std;
int main()
{
    // base container adaptor : sequential container(expect array and forward_list);
    deque<int> deq;
    stack<int> stk(deq);

    stack<string, vector<string>> str_stk;

    // stack
    stack<int> intStack;  // empty stack
    for (size_t ix = 0; ix != 9; ix++) {
        intStack.push(ix);
    }
    while (!intStack.empty()) {
        int value = intStack.top();
        intStack.pop();
        cout << value << " ";
    }
    cout << endl;

    // queue priority_queue;
    queue<int> q;
    priority_queue<int, vector<int>, greater<int>> heap;
    
    return 0;
}
