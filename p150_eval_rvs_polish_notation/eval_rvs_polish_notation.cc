/* Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 * Valid operators are +, -, *, /. Each operand may be an integer or another expression.
 * Some examples:
 *   ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
 *   ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
 */

#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
  public:
    int evalRPN(vector<string>& tokens) {
        stack<int> op_stack;
        for (auto &token : tokens) {
            int last = token.size()-1;
            if (token[last] >= '0' && token[last] <= '9') {
                int op = stoi(token);
                op_stack.push(op);
            } else {
                int op2 = op_stack.top();
                op_stack.pop();
                int op1 = op_stack.top();
                op_stack.pop();
                int op = 1;
                switch(token[0]) {
                    case '+': op = op1+op2; break;
                    case '-': op = op1-op2; break;
                    case '*': op = op1*op2; break;
                    case '/': op = op1/op2; break;
                    default: op = 1; break;
                }
                op_stack.push(op);
            }
        }
        return op_stack.top();
    }
};

int main() {
    Solution obj;
    auto run = [&obj](vector<string> tokens) { cout << obj.evalRPN(tokens) << endl; };
    run(vector<string>({"2", "1", "+", "3", "*"}));
    run(vector<string>({"4", "13", "5", "/", "+"}));
    run(vector<string>({"3", "-4", "+"}));
    return 0;
}
