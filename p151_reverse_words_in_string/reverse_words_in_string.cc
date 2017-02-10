/* Given an input string, reverse the string word by word.
 * For example,
 * Given s = "the sky is blue",
 * return "blue is sky the".
 * For C programmers: Try to solve it in-place in O(1) space.
 */

#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
  public:
    void reverseWords(string &s) {
        // step 1, remove multiple spaces, leading or trailing spaces
        bool space = false;
        for (auto iter = s.begin(); iter != s.end(); ) {
            if (*iter == ' ') {
                if (space) {
                    iter = s.erase(iter);
                } else {
                    space = true;
                    ++ iter;
                }
            } else {
                space = false;
                ++ iter;
            }
        }
        auto first = s.begin();
        if (*first == ' ') {
            s.erase(first);
        }
        auto last = prev(s.end());
        if (*last == ' ') {
            s.erase(last);
        }
        // step 2, reverse every letter
        int n = s.size();
        int left = 0;
        int right = n - 1;
        while (left < right) {
            swap(s[left], s[right]);
            ++ left;
            -- right;
        }
        // step 3, reverse letter within each word
        left = 0;
        right = 0;
        for (int i = 0; i <= n; ++i) {
            if (i == n || s[i] == ' ') {
                right = i-1;
                while (left < right) {
                    swap(s[left], s[right]);
                    ++ left;
                    -- right;
                }
                left = i+1;
                right = i+1;
            }
        }
    }
};

int main() {
    Solution obj;
    auto run = [&obj](string s)->void {
        cout << s << "==" << endl;
        obj.reverseWords(s);
        cout << s << "==" << endl;
    };
    run("   the sky  is blue  ");
    return 0;
}
