/* Given a string containing just the characters '(' and ')',
 * find the length of the longest valid (well-formed) parentheses substring.
 *
 * For "(()", the longest valid parentheses substring is "()", which has length = 2.
 *
 * Another example is ")()())", where the longest valid parentheses substring is "()()",
 * which has length = 4.
 */

#include <string>
#include <algorithm>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
  public:
    int longestValidParentheses(string s) {
        int size = s.size();
        int num_cur = 0;
        int num_max = 0;
        stack<pair<int, char>> parentheses;

        for (int i = 0; i < size; ++i) {
            if (s[i] == '(') {
                parentheses.push(make_pair(i, '('));
            } else if (s[i] == ')') {
                if (parentheses.empty() || parentheses.top().second == ')') {
                    parentheses.push(make_pair(i, ')'));
                } else {
                    parentheses.pop();
                    if (parentheses.empty()) {
                        num_cur = i + 1;
                    } else {
                        num_cur = i - parentheses.top().first;
                    }
                    num_max = max(num_max, num_cur);
                }
            } else {
                return -1;
            }
        }
        return num_max;
    }
};

int main() {
    Solution obj;
    cout << obj.longestValidParentheses(")()())") << endl;
    cout << obj.longestValidParentheses("(()") << endl;
    cout << obj.longestValidParentheses("()(()") << endl;
    return 0;
}
