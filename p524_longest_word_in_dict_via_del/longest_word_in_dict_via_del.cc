/**
 * Given a string and a string dictionary,
 * find the longest string in the dictionary that can be formed by deleting some characters of the given string.
 * If there are more than one possible results, return the longest word with the smallest lexicographical order.
 * If there is no possible result, return the empty string.
 * Example 1:
 * Input:
 * s = "abpcplea", d = ["ale","apple","monkey","plea"]
 * Output: 
 * "apple"
 * Example 2:
 * Input:
 * s = "abpcplea", d = ["a","b","c"]
 * Output: 
 * "a"
 * Note:
 * All the strings in the input will only contain lower-case letters.
 * The size of the dictionary won't exceed 1,000.
 * The length of all the strings in the input won't exceed 1,000.
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
    string findLongestWord(string s, vector<string>& d) {
        string res;
        for (const auto& w : d) {
            // check if d[i] can be formed by deleting char from s
            unsigned i = 0;
            unsigned j = 0;
            while (i < s.length() && j < w.length()) {
                if (s[i] == w[j]) {
                    ++j;
                }
                ++i;
            }
            if (j == w.length()) {
                // valid
                if (w.length() > res.length()) {
                    res = w;
                } else if (w.length() == res.length() && w < res) {
                    res = w;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution obj;
    auto run = [&](string s, vector<string> d) ->void {
        cout << s << " [ ";
        for (auto& x : d) {
            cout << x << " ";
        }
        cout << "]" << endl;
        cout << obj.findLongestWord(s, d) << endl;
    };
    run("abpcplea", {"ale", "apple", "monkey", "plea"});
    run("abpcplea", {"a", "b", "c"});
    run("bab", {"ba", "ab", "a", "b"});
    return 0;
}
