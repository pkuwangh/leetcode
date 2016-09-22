/* Implement regular expression matching with support for '.' and '*'.
 * '.' Matches any single character.
 * '*' Matches zero or more of the preceding element.
 *
 * The matching should cover the entire input string (not partial).
 *
 * The function prototype should be:
 * bool isMatch(const char *s, const char *p)
 *
 * Some examples:
 * isMatch("aa","a") → false
 * isMatch("aa","aa") → true
 * isMatch("aaa","aa") → false
 * isMatch("aa", "a*") → true
 * isMatch("aa", ".*") → true
 * isMatch("ab", ".*") → true
 * isMatch("aab", "c*a*b") → true
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define DEBUG

class Solution {
  public:
    bool isMatch(string s, string p) {  // p should match s
#ifdef DEBUG
        cout << s << " : " << p << " = ";
#endif
        return match(s, 0, p, 0);

        return false;
    }

    bool match(string s, size_t si, string p, size_t pi) {
        if (pi == p.size()) {
            return (si == s.size());
        }

        if (pi+1 < p.size() && p[pi+1] == '*') {
            if (si < s.size() && (p[pi] == s[si] || p[pi] == '.')) {
                return ( match(s, si+1, p, pi) || match(s, si, p, pi+2) );
            } else {
                return match(s, si, p, pi+2);
            }
        } else {
            if (si < s.size() && (p[pi] == s[si] || p[pi] == '.')) {
                return match(s, si+1, p, pi+1);
            } else {
                return false;
            }
        }

    }
};

int main() {
    Solution obj;

    cout << obj.isMatch("abc", "abcd") << endl;
    cout << obj.isMatch("abcd", "abc") << endl;
    cout << obj.isMatch("abcde", "abcde") << endl;

    cout << obj.isMatch("ab", "a*") << endl;
    cout << obj.isMatch("ab", ".*") << endl;
    cout << obj.isMatch("aab", "c*a*b") << endl;

    return 0;
}
