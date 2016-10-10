/* Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
 *
 * For example,
 * S = "ADOBECODEBANC"
 * T = "ABC"
 * Minimum window is "BANC".
 *
 * Note:
 * If there is no such window in S that covers all characters in T, return the empty string "".
 * If there are multiple such windows,
 * you are guaranteed that there will always be only one unique minimum window in S.
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
  public:
    string minWindow(string s, string t) {
        if (s.length() == 0 || t.length() == 0) {
            return string("");
        }
        // build a hash table that can tell if a char exists in t in O(1)
        // and count the total number of unique chars in t
        vector<int> tchar(256, 0);
        int total_cnt = 0;
        for (size_t i = 0; i < t.length(); ++i) {
            ++ total_cnt;
            ++ tchar[t[i]];
        }
        // maintain a hash table and a counter that track which char has been included
        vector<int> schar(256, 0);
        int cnt = 0;
        // use two pointers to scan s
        int size = s.length();
        int p = 0, q = 0;
        if (tchar[s[p]] > 0) {
            cnt = 1;
            schar[s[p]] = 1;
        }
        int start = 0, min_length = size+1;
        while (p < size) {
            if (cnt < total_cnt) {
                // currently not covering all chars
                ++ p;
                if (tchar[s[p]] > 0) {
                    // new char in t
                    if (schar[s[p]] < tchar[s[p]]) {
                        ++ cnt;
                    }
                    ++ schar[s[p]];
                }
            } else {
                // covering all chars
                if (p - q + 1 < min_length) {
                    min_length = p - q + 1;
                    start = q;
                }
                // try pushing left pointer towards right
                if (tchar[s[q]] > 0) {
                    // removed a char that is in t
                    if (schar[s[q]] <= tchar[s[q]]) {
                        -- cnt;
                    }
                    -- schar[s[q]];
                }
                ++ q;
            }
        }

        if (min_length > size) {
            min_length = 0;
        }
        return s.substr(start, min_length);
    }
};

int main() {
    Solution obj;
    cout << obj.minWindow("a", "aa") << endl;
    cout << obj.minWindow("aab", "aab") << endl;
    cout << obj.minWindow("CBA", "AC") << endl;
    cout << obj.minWindow("ADOBECODEBANC", "ABC") << endl;
    return 0;
}
