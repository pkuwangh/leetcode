/* Given a string S and a string T, count the number of distinct subsequences of T in S.
 * A subsequence of a string is a new string which is formed from the original string
 * by deleting some (can be none) of the characters without disturbing the relative positions
 * of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
 * Here is an example:
 * S = "rabbbit", T = "rabbit"
 * Return 3.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
  public:
    int numDistinct(string s, string t) {
        // dp[i][j] represents the number of subsequence of T[0:i-1] in S[0:j-1]
        int nt = t.size();
        int ns = s.size();
        vector<vector<int>> dp(nt+1, vector<int>(ns+1,0));
        // for j < i, dp[i][j] = 0
        // dp[0][:] = 1, dp[1:][0] = 0;
        fill(dp[0].begin(), dp[0].end(), 1);
        for (int i = 1; i <= nt; ++i) {
            for (int j = i; j <= ns; ++j) {
                if (t[i-1] == s[j-1]) {
                    // take s[j-1] or not take it
                    dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
                } else {
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
        return dp[nt][ns];
    }
};

int main() {
    Solution obj;
    cout << obj.numDistinct("rabbbit", "rabbit") << endl;
    cout << obj.numDistinct("ccc", "c") << endl;
    cout << obj.numDistinct("a", "aa") << endl;
    return 0;
}
