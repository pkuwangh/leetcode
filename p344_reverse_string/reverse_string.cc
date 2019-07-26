/**
 * Write a function that reverses a string. The input string is given as an array of characters char[].
 * Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
 * You may assume all the characters consist of printable ascii characters.
 * Example 1:
 * Input: ["h","e","l","l","o"]
 * Output: ["o","l","l","e","h"]
 * Example 2:
 * Input: ["H","a","n","n","a","h"]
 * Output: ["h","a","n","n","a","H"]
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
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;
        while (left <= right) {
            swap(s[left], s[right]);
            ++ left;
            -- right;
        }
    }
};

int main() {
    Solution obj;
    auto run = [&](vector<char> s) ->void {
        for (auto& c : s) {
            cout << c << " ";
        }
        cout << endl;
        obj.reverseString(s);
        for (auto& c : s) {
            cout << c << " ";
        }
        cout << endl;
    };
    run({'h', 'e', 'l', 'l', 'o'});
    run({'H', 'a', 'n', 'n', 'a', 'h'});
    return 0;
}
