/* The count-and-say sequence is the sequence of integers beginning as follows:
 * 1, 11, 21, 1211, 111221, ...
 *
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * Given an integer n, generate the nth sequence.
 *
 * Note: The sequence of integers will be represented as a string.
 */

#include <iostream>
#include <string>
using namespace std;

class Solution {
  public:
    string countAndSay(int n) {
        string ret = "1";
        for (int i = 1; i < n; ++i) {
            string temp;
            char prev = ret[0];
            int count = 1;
            for (unsigned int j = 1; j < ret.size(); ++j) {
                if (ret[j] == prev) {
                    ++ count;
                } else {
                    char cnt = char('0' + count);
                    temp.push_back(cnt);
                    temp.push_back(prev);
                    prev = ret[j];
                    count = 1;
                }
            }
            char cnt = char('0' + count);
            temp.push_back(cnt);
            temp.push_back(prev);
            ret = temp;
        }
        return ret;
    }
};

int main() {
    Solution obj;
    for (int i = 1; i <= 5; ++i) {
        cout << obj.countAndSay(i) << endl;
    }
    return 0;
}
