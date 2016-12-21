/* Given a string, determine if it is a palindrome,
 * considering only alphanumeric characters and ignoring cases.
 *
 * For example,
 * "A man, a plan, a canal: Panama" is a palindrome.
 * "race a car" is not a palindrome.
 *
 * Note:
 * Have you consider that the string might be empty?
 * This is a good question to ask during an interview.
 * For the purpose of this problem, we define empty string as valid palindrome.
 */

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Solution {
  public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = (int)s.size() - 1;
        while (start < end) {
            if (!isalnum(s[start])) {
                ++ start;
                continue;
            }
            if (!isalnum(s[end])) {
                -- end;
                continue;
            }
            if (tolower(s[start]) == tolower(s[end])) {
                ++ start;
                -- end;
            } else {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution obj;
    cout << obj.isPalindrome("A man, a plan, a canal: Panama") << endl;
    cout << obj.isPalindrome("race a car") << endl;
    cout << obj.isPalindrome(",.") << endl;
    return 0;
}
