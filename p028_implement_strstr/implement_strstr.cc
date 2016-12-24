/* Implement strStr().
 * Returns the index of the first occurrence of needle in haystack,
 * or -1 if needle is not part of haystack.
 */

#include <iostream>
#include <string>
using namespace std;

class Solution {
  public:
    int strStr(string haystack, string needle) {
        // brute-force method
        int size_h = haystack.size();
        int size_n = needle.size();
        if (size_n == 0) return 0;
        for (int i = 0; i < (size_h - size_n + 1); ++i) {
            // try each element in haystack as first char
            bool match = true;
            for (int j = 0; j < size_n; ++j) {
                if (haystack[i+j] != needle[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    Solution obj;
    cout << obj.strStr("ababcdef", "abcd") << endl;
    return 0;
}
