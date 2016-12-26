/* Given a set of candidate numbers (C) (without duplicates) and a target number (T),
 * find all unique combinations in C where the candidate numbers sums to T.
 *
 * The same repeated number may be chosen from C unlimited number of times.
 *
 * Note:
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * For example, given candidate set [2, 3, 6, 7] and target 7, 
 * A solution set is: 
 * [
 *   [7],
 *   [2, 2, 3]
 * ]
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> all_sols;
        vector<int> sol;
        // sort
        sort(candidates.begin(), candidates.end(),
                [](const int& a, const int& b)->bool { return a < b; });
        // DFS
        findSol(all_sols, sol, candidates, target, 0);
        return all_sols;
    }

    // DFS
    void findSol(vector<vector<int>>& all_sols, vector<int>& sol,
                 vector<int>& candidates, int target, unsigned int start_index)
    {
        for (unsigned int i = start_index; i < candidates.size(); ++i) {
            if (candidates[i] <= target) {
                // include this node
                sol.push_back(candidates[i]);
                if (candidates[i] == target) {
                    // find a solution
                    all_sols.push_back(sol);
                } else {
                    // go deeper, still starting from i
                    findSol(all_sols, sol, candidates, target - candidates[i], i);
                }
                // roll back
                sol.pop_back();
            } else {
                break;
            }
        }
    }
};

int main() {
    Solution obj;
    auto run = [&](vector<int> candidates, int target) -> void {
        auto ans = obj.combinationSum(candidates, target);
        for (auto & comb : ans) {
            for (auto & n : comb) {
                cout << n << " ";
            }
            cout << endl;
        }
    };
    run({2, 3, 6, 7}, 7);
    return 0;
}
