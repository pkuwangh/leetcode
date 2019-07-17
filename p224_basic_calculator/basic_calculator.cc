/**
 * Implement a basic calculator to evaluate a simple expression string.
 * The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .
 * Example 1:
 * Input: "1 + 1"
 * Output: 2
 * Example 2:
 * Input: " 2-1 + 2 "
 * Output: 3
 * Example 3:
 * Input: "(1+(4+5+2)-3)+(6+8)"
 * Output: 23
 * Note:
 * You may assume that the given expression is always valid.
 * Do not use the eval built-in library function.
*/

#include <vector>
#include <stack>
#include <cassert>
#include <utility>
#include <string>
#include <iostream>
using namespace std;

class Solution {
  public:
    int calculate(string s) {
        int idx = 0;
        int ans = 0;
        int sign = 1;
        while (idx < s.length()) {
            if (s[idx] == ' ') {
                // skip
            } else if (s[idx] >= '0' && s[idx] <= '9') {
                int num = 0;
                while (idx < s.length() && s[idx] >= '0' && s[idx] <= '9') {
                    num = 10*num + (s[idx] - '0');
                    ++ idx;
                }
                ans += sign * num;
                idx -= 1;
            } else if (s[idx] == '+') {
                sign = 1;
            } else if (s[idx] == '-') {
                sign = -1;
            } else if (s[idx] == '(') {
                // push into stack
                ops.push(make_pair(ans, sign));
                ans = 0;
                sign = 1;
            } else if (s[idx] == ')') {
                // pop from stack
                auto item = ops.top();
                ans = item.first + item.second * ans;
                sign = 1;
                ops.pop();
            } else {
                cout << s[idx] << endl;
                assert(0);
            }
            //cout << "idx=" << idx << " ans=" << ans << endl;
            idx += 1;
        }
        return ans;
    }

  private:
    stack<pair<int, int>> ops;
};

int main() {
    Solution obj;
    auto run = [&](string s)->void {
        cout << s << " = " << obj.calculate(s) << endl;
    };
    run("5 - (6 - 3)");
    run("1 + 1");
    run(" 2-1 + 2 ");
    run(" 2-14 + 2 ");
    run("(1+(4+5+2)-3)+(6+8)");
    run("2147483647");
    return 0;
}
