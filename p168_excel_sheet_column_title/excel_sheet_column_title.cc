/* Given a positive integer, return its corresponding column title as appear in an Excel sheet.
 * For example:
 *     1 -> A
 *     2 -> B
 *     3 -> C
 *     ...
 *     26 -> Z
 *     27 -> AA
 *     28 -> AB 
 */

#include <iostream>
#include <string>
#include <deque>
using namespace std;

class Solution {
  public:
    string convertToTitle(int n) {
        string ans;
        if (n == 0) return ans;
        deque<char> str;
        do {
            n = n - 1;
            char c = 'A' + n % 26;
            n = n / 26;
            str.push_front(c);
        } while (n > 0);
        for (auto &c : str) {
            ans.push_back(c);
        }
        return ans;
    }
};

int main() {
    Solution obj;
    cout << obj.convertToTitle(1) << endl;
    cout << obj.convertToTitle(26) << endl;
    cout << obj.convertToTitle(28) << endl;
    return 0;
}
