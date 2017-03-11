/* Given a string S, you are allowed to convert it to a palindrome by adding characters
 * in front of it.
 * Find and return the shortest palindrome you can find by performing this transformation.
 * For example:
 * Given "aacecaaa", return "aaacecaaa".
 * Given "abcd", return "dcbabcd".
 */

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
  public:
    string shortestPalindrome(string s) {
        int n = s.length();
        if (n < 2) return s;
        // reverse string
        reverse(s.begin(), s.end());
        // keep inserting to position n
        bool is_palindrome = false;
        int num = 0;
        while (!is_palindrome) {
            int left = num;
            int right = n-1;
            while (left <= right) {
                if (s[left] != s[right]) break;
                ++ left;
                -- right;
            }
            is_palindrome = (left > right);
            if (!is_palindrome) {
                if (num == 0) {
                    s += s[0];
                } else {
                    s.insert(n, 1, s[num]);
                }
                ++ num;
            }
        }
        // reverse back
        reverse(s.begin(), s.end());
        return s;
    }
};

int main() {
    Solution obj;
    cout << obj.shortestPalindrome("abcd") << endl;
    cout << obj.shortestPalindrome("abbacd") << endl;
    cout << obj.shortestPalindrome("") << endl;
    cout << obj.shortestPalindrome("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa") << endl;
    return 0;
}
