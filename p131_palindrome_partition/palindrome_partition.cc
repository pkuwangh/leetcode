/* Given a string s, partition s such that every substring of the partition is a palindrome.
 * Return all possible palindrome partitioning of s.
 * For example, given s = "aab",
 * Return
 * [
 *   ["aa","b"],
 *   ["a","a","b"]
 * ]
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        // build a matrix; dp[i][j] specifies if s[i:j] is a palindrome
        vector<vector<int>> dp(n, vector<int>(n, 0));
        // init dp[i][i] = 1
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1;
        }
        // init dp[i][i+1]
        for (int i = 0; (i+1) < n; ++i) {
            dp[i][i+1] = (s[i] == s[i+1]);
        }
        // dynamic programming
        for (int diff = 2; diff < n; ++diff) {
            for (int i = 0; i+diff < n; ++i) {
                dp[i][i+diff] = (s[i] == s[i+diff]) && (dp[i+1][i+diff-1]);
            }
        }
        // DFS
        vector<vector<string>> all_sols;
        vector<string> sol;
        findSol(all_sols, sol, s, dp, 0);
        return all_sols;
    }

    void findSol(vector<vector<string>>& all_sols, vector<string>& sol, const string &s,
                 const vector<vector<int>>& isPalindrome, uint32_t start)
    {
        if (start == s.size()) {
            // find a solution
            all_sols.push_back(sol);
            return;
        }
        // scan all possibilities at current step
        for (uint32_t end = start; end < s.size(); ++end) {
            if (isPalindrome[start][end]) {
                // take it
                sol.push_back(s.substr(start, end-start+1));
                // dfs
                findSol(all_sols, sol, s, isPalindrome, end+1);
                // roll back
                sol.pop_back();
            }
        }
    }
};

int main() {
    Solution obj;
//    auto ans = obj.partition("aab");
    auto ans = obj.partition("cbbbcc");
    for (auto &strs : ans) {
        for (auto &str : strs) {
            cout << str << " ";
        }
        cout << endl;
    }
    return 0;
}
