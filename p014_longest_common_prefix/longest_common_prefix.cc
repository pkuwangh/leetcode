/* Write a function to find the longest common prefix string amongst an array of strings.
 */

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
  public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";

        if (strs.size() == 0) {
            return prefix;
        }

        for (size_t i = 0; i < strs[0].length(); ++i) {
            char c = strs[0][i];
            for (size_t k = 1; k < strs.size(); ++k) {
                if ( ! (i < strs[k].length() && strs[k][i] == c) ) {
                    return prefix;
                }
            }
            prefix += c;
        }
        return prefix;
    }
};

int main() {
    Solution obj;

    vector<string> strs;

    strs.push_back("ab");
    strs.push_back("abce");
    strs.push_back("abcf");

    cout << obj.longestCommonPrefix(strs) << endl;

    return 0;
}
