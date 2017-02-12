/* Related to question Excel Sheet Column Title
 * Given a column title as appear in an Excel sheet, return its corresponding column number.
 * For example:
 *     A -> 1
 *     B -> 2
 *     C -> 3
 *     ...
 *     Z -> 26
 *     AA -> 27
 *     AB -> 28 
 */

#include <string>
#include <iostream>
using namespace std;

class Solution {
  public:
    int titleToNumber(string s) {
        int num = 0;
        for (auto &c : s) {
            int n = c - 'A' + 1;
            num = num*26 + n;
        }
        return num;
    }
};

int main() {
    Solution obj;
    cout << obj.titleToNumber("A") << endl;
    cout << obj.titleToNumber("Z") << endl;
    cout << obj.titleToNumber("AB") << endl;
    return 0;
}
