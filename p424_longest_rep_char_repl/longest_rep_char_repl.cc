/**
 * Given a string s that consists of only uppercase English letters, you can perform at most k operations on that string.
 * In one operation, you can choose any character of the string and change it to any other uppercase English character.
 * Find the length of the longest sub-string containing all repeating letters you can get after performing the above operations.
 * Note:
 * Both the string's length and k will not exceed 104.
 * Example 1:
 * Input:
 * s = "ABAB", k = 2
 * Output:
 * 4
 * Explanation:
 * Replace the two 'A's with two 'B's or vice versa.
 * Example 2:
 * Input:
 * s = "AABABBA", k = 1
 * Output:
 * 4
 * Explanation:
 * Replace the one 'A' in the middle with 'B' and form "AABBBBA".
 * The substring "BBBB" has the longest repeating letters, which is 4.
 */

#include <cassert>
#include <cstdint>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <list>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <functional>
#include <algorithm>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
        int runner = 0;
        int walker = 0;
        int max_count = 0;
        int res = 0;
        while (runner < s.length()) {
            const int index = s[runner] - 'A';
            ++ count[index];
            max_count = max(max_count, count[index]);
            ++ runner;
            while (runner - walker - max_count > k) {
                // move left pointer
                -- count[s[walker]-'A'];
                ++ walker;
            }
            res = max(res, runner - walker);
        }
        return res;
    }

    /*
    int characterReplacement(string s, int k) {
        int max_length = 0;
        // two pointers, start & end
        int start = 0;
        while (start < s.length()) {
            int end = start;
            int allowance = k;
            while (end < s.length()) {
                if (s[start] != s[end]) {
                    if (allowance > 0) {
                        // try replacing that char
                        -- allowance;
                    } else {
                        break;
                    }
                }
                ++ end;
            }
            // calculate max
            int new_length = end - start;
            if (end == s.length()) {
                // special treatment
                int s = start - 1;
                while (s >= 0 && allowance > 0) {
                    // extend to left
                    ++ new_length;
                    -- s;
                    -- allowance;
                }
            }
            max_length = max(new_length, max_length);
            // move start forward
            ++ start;
            while (start < s.length() && s[start] == s[start-1]) {
                ++ start;
            }
        }
        return max_length;
    }
    */
};

int main() {
    Solution obj;
    auto run = [&](string s, int k) ->void {
        cout << s << ", k=" << k << endl;
        cout << obj.characterReplacement(s, k) << endl;
    };
    run("ABBB", 2);
    run("ABAA", 0);
    run("ABAB", 2);
    run("AABABBA", 1);
    return 0;
}
