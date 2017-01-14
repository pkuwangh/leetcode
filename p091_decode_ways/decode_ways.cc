/* A message containing letters from A-Z is being encoded to numbers
 * using the following mapping:
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * Given an encoded message containing digits, determine the total number of ways to decode it.
 * For example,
 * Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
 * The number of ways decoding "12" is 2.
 */

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
  public:
    // dp[i+1], count # of decodings for s[0:i] that has length of i+1
    int numDecodings(string s) {
        if (s.size() == 0 || s[0] < '1' || s[0] > '9') return 0;
        int size = s.size();
        vector<int> dp(size+1, 0);
        // init
        dp[0] = 1;
        dp[1] = 1;
        // dp
        for (int i = 1; i < size; ++i) {
            if (s[i] < '0' || s[i] > '9') return 0;
            int v = (s[i-1]-'0')*10 + (s[i]-'0');
            // decode s[i-1:i] as one char
            if (v <= 26 && v >= 10) dp[i+1] += dp[i-1];
            // decode s[i-1] & s[i] as separate char
            if (s[i] != '0') dp[i+1] += dp[i];
        }
        return dp[size];
    }
};

int main() {
    Solution obj;
    cout << obj.numDecodings("12") << endl;
    cout << obj.numDecodings("123") << endl;
    return 0;
}
