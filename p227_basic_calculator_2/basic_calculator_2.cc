/**
 * Implement a basic calculator to evaluate a simple expression string.
 * The expression string contains only non-negative integers, +, -, *, / operators and empty spaces.
 * The integer division should truncate toward zero.
 * Example 1:
 * Input: "3+2*2"
 * Output: 7
 * Example 2:
 * Input: " 3/2 "
 * Output: 1
 * Example 3:
 * Input: " 3+5 / 2 "
 * Output: 5
 * Note:
 * You may assume that the given expression is always valid.
 * Do not use the eval built-in library function.
 */

#include <stack>
#include <utility>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
  public:
    int calculate(string s) {
        // * and / can proceed, + and - should enter a stack
        stack<pair<int, int>> ops;
        int ans = 0;
        int op = 0;   // 0 is +/-, 1 is *, -1 is /
        unsigned idx = 0;
        while (idx <= s.length()) {
            if (idx == s.length() || s[idx] == '+' || s[idx] == '-') {
                // first empty the stack
                while (!ops.empty()) {
                    auto x = ops.top();
                    ans = x.first + x.second * ans;
                    ops.pop();
                }
                // push previous and & op into stack
                if (idx < s.length()) {
                    if (s[idx] == '-') {
                        ops.push(make_pair(ans, -1));
                    } else {
                        ops.push(make_pair(ans, 1));
                    }
                    ans = 0;  // reset ans
                }
            } else if (s[idx] >= '0' && s[idx] <= '9') {
                int num = s[idx] - '0';
                while (idx+1 < s.length() && s[idx+1] >= '0' && s[idx+1] <= '9') {
                    num = 10*num + (s[idx+1] - '0');
                    ++ idx;
                }
                if (op == 1) {
                    ans = ans * num;
                } else if (op == -1) {
                    ans = ans / num;
                } else {
                    ans = num;
                }
                op = 0; // reset op
            } else if (s[idx] == '*') {
                op = 1;
            } else if (s[idx] == '/') {
                op = -1;
            } else {
                // skip
            }
            ++ idx;
        }
        return ans;
    }
};

int main() {
    Solution obj;
    auto run = [&](string s)->void {
        cout << s << " = ";
        cout << obj.calculate(s) << endl;
    };
    run("3+2*2");
    run(" 3/2 ");
    run(" 3+5 / 2 ");
    run("2147483647");
    run("1-1");
    run("1-1+1");
    run("2-3+4");
    return 0;
}
