/**
 * Given a non-empty string s and a dictionary wordDict containing a list of non-empty words,
 * add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences.
 * Note:
 * The same word in the dictionary may be reused multiple times in the segmentation.
 * You may assume the dictionary does not contain duplicate words.
 * Example 1:
 * Input:
 * s = "catsanddog"
 * wordDict = ["cat", "cats", "and", "sand", "dog"]
 * Output:
 * [
 *   "cats and dog",
 *   "cat sand dog"
 * ]
 *
 * Example 2:
 * Input:
 * s = "pineapplepenapple"
 * wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
 * Output:
 * [
 *   "pine apple pen apple",
 *   "pineapple pen apple",
 *   "pine applepen apple"
 * ]
 * Explanation: Note that you are allowed to reuse a dictionary word.
 *
 * Example 3:
 * Input:
 * s = "catsandog"
 * wordDict = ["cats", "dog", "sand", "and", "cat"]
 * Output:
 * []
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>
#include <unordered_set>
using namespace std;

class Solution_back {
public:
    // again, DFS gets time limit exceeded
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        // build a hashset dict
        unordered_set<string> dict;
        for (const auto& word : wordDict) {
            dict.insert(word);
        }
        // dfs
        vector<list<string>> all_sols;
        list<string> sol;
        dfs(s, dict, 0, all_sols, sol);
        // construct the final vector of sentences
        vector<string> final_sols;
        for (auto& one_sol : all_sols) {
            string sentence = one_sol.front();
            one_sol.pop_front();
            while (!one_sol.empty()) {
                sentence.append(" " + one_sol.front());
                one_sol.pop_front();
            }
            final_sols.emplace_back(sentence);
        }
        return final_sols;
    }

    void dfs(const string& s, const unordered_set<string>& dict, unsigned start, vector<list<string>>& all_sols, list<string>& sol) {
        // terminating point
        if (start == s.size()) {
            // find a valid solution
            all_sols.emplace_back(sol);
            return;
        }
        // find a valid word starting at s
        for (unsigned end = start; end < s.size(); ++end) {
            const unsigned length = end - start + 1;
            const string word = s.substr(start, length);
            if (dict.count(word) > 0) {
                // a valid word
                // track as a possible solution
                sol.push_back(word);
                // recursive call
                dfs(s, dict, end + 1, all_sols, sol);
                // roll back
                sol.pop_back();
            }
        }
    }
};

class Solution {
  public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        // build a hashset dict
        unordered_set<string> dict;
        for (const auto& word : wordDict) {
            dict.insert(word);
        }
        // DFS has repeated computations
        // 1D DP should avoid that
        // valid[i] indicating if s[0:i-1] has valid solutions
        // sols[i] include all solutions for s[0:i-1]
        const int length = s.length();
        vector<bool> valid(length + 1, false);
        // tracking all valid sentences at each point got memory limit exceeded
        // track the starting point of each word
        vector<list<int>> sols(length + 1);
        valid[0] = true;
        for (int i = 1; i < length + 1; ++i) {
            for (int x = 0; x < i; ++x) {
                // x is end of last word
                if (valid[x]) {
                    // can be built starting from x+1
                    const string word = s.substr(x, i-x);
                    if (dict.count(word)) {
                        // a valid word
                        valid[i] = true;
                        // track all solutions at this point
                        sols[i].push_back(x);
                    }
                }
            }
        }
        // dfs backtracking to construct final solutions
        return construct(s, sols, length);
    }

    vector<string> construct(const string& s, const vector<list<int>>& sols, int end) {
        vector<string> ans;
        if (end > 0) {
            for (const auto& x : sols[end]) {
                const string word = s.substr(x, end-x);
                const vector<string> prev_ans = construct(s, sols, x);
                for (auto sentence : prev_ans) {
                    if (sentence.length() > 0) {
                        sentence.append(" ");
                    }
                    sentence.append(word);
                    ans.emplace_back(sentence);
                }
            }
        } else {
            ans.emplace_back("");
        }
        return ans;
    }
};

int main() {
    Solution obj;
    auto run = [&](string s, vector<string> wordDict) {
        auto ans = obj.wordBreak(s, wordDict);
        for (auto& setence : ans) {
            cout << setence << endl;
        }
    };
    run("catsanddog", {"cat", "cats", "and", "sand", "dog"});
    run("pineapplepenapple", {"apple", "pen", "applepen", "pine", "pineapple"});
    run("catsandog", {"cats", "dog", "sand", "and", "cat"});
}
