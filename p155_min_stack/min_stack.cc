/* Design a stack that supports push, pop, top,
 * and retrieving the minimum element in constant time.
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * getMin() -- Retrieve the minimum element in the stack.
 * Example:
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin();   --> Returns -3.
 * minStack.pop();
 * minStack.top();      --> Returns 0.
 * minStack.getMin();   --> Returns -2.
 */

#include <iostream>
#include <stack>
#include <map>
using namespace std;

class MinStack {
  public:
    stack<int> _stack;
    map<int, int> _map;

    MinStack() {
    }

    void push(int x) {
        _stack.push(x);
        if (_map.count(x)) {
            ++ _map[x];
        } else {
            _map[x] = 1;
        }
    }

    void pop() {
        int x = _stack.top();
        _stack.pop();
        -- _map[x];
        if (_map[x] == 0) {
            _map.erase(x);
        }
    }

    int top() {
        return _stack.top();
    }

    int getMin() {
        return (_map.begin())->first;
    }
};

int main() {
    MinStack* obj = new MinStack();
    obj->push(-2);
    obj->push(-2);
    obj->push(0);
    obj->push(-3);
    cout << obj->getMin() << endl;
    obj->pop();
    cout << obj->top() << endl;
    cout << obj->getMin() << endl;
    obj->pop();
    cout << obj->getMin() << endl;
    return 0;
}
