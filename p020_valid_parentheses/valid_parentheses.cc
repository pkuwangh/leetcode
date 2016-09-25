/* Given a string containing just the characters
 * '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 *
 * The brackets must close in the correct order,
 * "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 */

#include <string>
#include <iostream>
#include <stack>

using namespace std;

class Solution {
  public:
    bool isValid(string s) {
        stack<char> st;
        for (size_t i = 0; i < s.length(); ++i) {
            if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
                if (st.empty() || st.top() != s[i]) {
                    return false;
                } else {
                    st.pop();
                }
            } else {
                switch(s[i]) {
                    case '(': st.push(')'); break;
                    case '{': st.push('}'); break;
                    case '[': st.push(']'); break;
                    default: return false;
                }
            }
        }
        return st.empty();
    }
};

int main() {
    Solution obj;

    cout << obj.isValid("()[]{}") << endl;
    cout << obj.isValid("([)]") << endl;
    cout << obj.isValid("([") << endl;
    cout << obj.isValid("{}][}}{[))){}{}){(}]))})[({") << endl;
    return 0;
}
