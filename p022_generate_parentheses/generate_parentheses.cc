/* Given n pairs of parentheses,
 * write a function to generate all combinations of well-formed parentheses.
 * For example, given n = 3, a solution set is:
 * [
 *   "((()))",
 *   "(()())",
 *   "(())()",
 *   "()(())",
 *   "()()()"
 * ]
 */

#include <iostream>
#include <vector>
#include <string>
#include <cassert>
using namespace std;

class Solution {
  public:
    vector<string> generateParenthesis(int n) {
        vector<string> all_sols;
        string sol;
        findParenthesis(all_sols, sol, n, 0, 0);
        return all_sols;
    }

    void findParenthesis(vector<string>& all_sols, string& sol, int n, int left, int right) {
        if (left+right == n*2) {
            // find a combination
            assert (left == n);
            all_sols.push_back(sol);
        }

        if (left < n) {
            // try '('
            sol.push_back('(');
            findParenthesis(all_sols, sol, n, left+1, right);
            // roll back
            sol.pop_back();
        }
        if (right < left) {
            // try ')'
            sol.push_back(')');
            findParenthesis(all_sols, sol, n, left, right+1);
            sol.pop_back();
        }
    }
};

int main() {
    Solution obj;
    auto ans = obj.generateParenthesis(3);
    for (const auto & s : ans) {
        cout << s << endl;
    }
    return 0;
}
