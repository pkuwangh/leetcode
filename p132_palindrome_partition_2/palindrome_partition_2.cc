/* Given a string s, partition s such that every substring of the partition is a palindrome.
 * Return the minimum cuts needed for a palindrome partitioning of s.
 * For example, given s = "aab",
 * Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
 */

#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
  public:
    int minCut(string s) {
        int n = s.size();
        // step 1: build a matrix, isPal[i][j] represents whether s[i:j] is a palindrome
        vector<vector<int>> isPal(n, vector<int>(n, 0));
        // init isPal[i][i] = 1
        for (int i = 0; i < n; ++i) isPal[i][i] = 1;
        // init isPal[i][i+1] = 1
        for (int i = 0; i < n-1; ++i) {
            //isPal[i][i+1] = 1;
            isPal[i][i+1] = (s[i] == s[i+1]);  // this seems to be assumption of leetcode
        }
        // dynamic programming
        for (int diff = 2; diff < n; ++diff) {
            for (int i = 0; i+diff < n; ++i) {
                isPal[i][i+diff] = isPal[i+1][i+diff-1] && (s[i] == s[i+diff]);
            }
        }
        // step 2: dynamic programming, dp[i] represents min cut of s[0:i-1]
        vector<int> dp(n+1, n);
        dp[0] = -1;   // such that if s[0:i-1] is palindrome, dp[i] = 0;
        for (int i = 1; i <= n; ++i) {
            // enumerate cut point
            for (int j = i-1; j >= 0; --j) {
                if (isPal[j][i-1]) {
                    dp[i] = min(dp[i], dp[j]+1);
                }
            }
        }
        return dp[n];
    }
};

int main() {
    Solution obj;
    cout << obj.minCut("aab") << endl;
    cout << obj.minCut("ab") << endl;
    cout << obj.minCut("a") << endl;
}
