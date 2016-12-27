/* Given a collection of candidate numbers (C) and a target number (T),
 * find all unique combinations in C where the candidate numbers sums to T.
 * Each number in C may only be used once in the combination.
 *
 * Note:
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8, 
 * A solution set is: 
 * [
 *   [1, 7],
 *   [1, 2, 5],
 *   [2, 6],
 *   [1, 1, 6]
 * ]
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> all_sols;
        vector<int> sol;
        // sort
        sort(candidates.begin(), candidates.end(),
                [](const int& a, const int& b)->bool {return a < b;});
        // DFS
        findCombination(all_sols, sol, candidates, target, 0);
        return all_sols;
    }

    // DFS
    void findCombination(vector<vector<int>>& all_sols, vector<int>& sol,
                         vector<int>& candidates, int target, unsigned int start_index)
    {
        for (unsigned int i = start_index; i < candidates.size(); ++i) {
            // avoid duplicates
            if (i > start_index && candidates[i] == candidates[i-1]) {
                continue;
            }
            if (candidates[i] <= target) {
                // include this number
                sol.push_back(candidates[i]);
                if (candidates[i] == target) {
                    // find a solution
                    all_sols.push_back(sol);
                } else {
                    // search deeper
                    findCombination(all_sols, sol, candidates, target - candidates[i], i+1);
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
        auto ans = obj.combinationSum2(candidates, target);
        for (auto & comb : ans) {
            for (auto & n : comb) {
                cout << n << " ";
            }
            cout << endl;
        }
    };
    run({10, 1, 2, 7, 6, 1, 5}, 8);
    return 0;
}
