/* Given a string s consists of upper/lower-case alphabets and empty space characters ' ',
 * return the length of last word in the string.
 * If the last word does not exist, return 0.
 *
 * Note: A word is defined as a character sequence consists of non-space characters only.
 * For example, 
 * Given s = "Hello World",
 * return 5.
 */

#include <iostream>
#include <string>
using namespace std;

class Solution {
  public:
    int lengthOfLastWord(string s) {
        int num = 0;
        bool counting = false;
        for (unsigned int i = 0; i < s.size(); ++i) {
            if (isalpha(s[i])) {
                if (counting) {
                    ++ num;
                } else {
                    num = 1;
                    counting = true;
                }
            } else {
                counting = false;
            }
        }
        return num;
    }
};

int main() {
    Solution obj;
    cout << obj.lengthOfLastWord("Hello my World") << endl;
    return 0;
}
