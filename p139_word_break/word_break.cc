/* Given a non-empty string s and a dictionary wordDict containing a list of non-empty words,
 * determine if s can be segmented into a space-separated sequence of one or more dictionary
 * words. You may assume the dictionary does not contain duplicate words.
 * For example, given
 * s = "leetcode",
 * dict = ["leet", "code"].
 * Return true because "leetcode" can be segmented as "leet code".
 */

#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
using namespace std;

// DFS will get Time Limit Exceeded
#if 0
class Solution {
  public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // build a hash table from input dictionary
        unordered_set<string> dict;
        for (auto &word : wordDict) {
            dict.insert(word);
        }
        // DFS
        return wordSegment(s, 0, dict);
    }

    bool wordSegment(const string &s, int start, const unordered_set<string>& dict) {
        int n = s.size();
        if (start == n) return true;
        bool found = false;
        for (int end = start; end < n; ++end) {
            string word = s.substr(start, end-start+1);
            if (dict.count(word)) {
                found |= wordSegment(s, end+1, dict);
            }
        }
        return found;
    }
#endif

class Solution {
  public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // build a hash table from input dictionary
        unordered_set<string> dict;
        for (auto &word : wordDict) {
            dict.insert(word);
        }
        // dynamic programming
        // dp[i] represents if s[0:i-1] is a valid word break
        int n = s.size();
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            bool found = false;
            for (int j = i-1; j >= 0; --j) {
                string word = s.substr(j, i-j);
                found |= (dp[j] > 0) && (dict.count(word) > 0);
            }
            dp[i] = found;
        }
        return (dp[n] > 0);
    }
};

int main() {
    Solution obj;
    vector<string> wordDict({"leet", "code"});
    cout << obj.wordBreak("leetcode", wordDict) << endl;
    return 0;
}
