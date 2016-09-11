/* Given a string, find the length of the longest substring without repeating characters.
 *
 * Examples:
 * Given "abcabcbb", the answer is "abc", which the length is 3.
 * Given "bbbbb", the answer is "b", with the length of 1.
 * Given "pwwkew", the answer is "wke", with the length of 3.
 * Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// two pointers, sliding window
class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
        size_t begin = 0;
        size_t end = 0;
        int max_length = 0;
        vector<bool> exist(256, false);
        while (end < s.length()) {
            if (!exist[s[end]]) {
                exist[s[end]] = true;
                ++end;
                int length = end - begin;
                if (length > max_length) {
                    max_length = length;
                }
            } else {
                while (exist[s[end]]) {
                    exist[s[begin]] = false;
                    ++begin;
                }
            }
        }
        return max_length;
    }
};

int main()
{
    Solution obj;

//    string str = "pwwkew";
//    string str = "bbbbb";
    string str = "abcabcbb";
    cout << str << endl;
    cout << obj.lengthOfLongestSubstring(str);
    cout << endl;

    return 0;
}

