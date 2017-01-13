/* Given a collection of integers that might contain duplicates, nums,
 * return all possible subsets.
 * Note: The solution set must not contain duplicate subsets.
 * For example,
 * If nums = [1,2,2], a solution is:
 * [
 *   [2],
 *   [1],
 *   [1,2,2],
 *   [2,2],
 *   [1,2],
 *   []
 * ]
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> all_sols;
        vector<int> sol;
        all_sols.push_back(sol);
        findSubsets(all_sols, sol, nums);
        return all_sols;
    }

    void findSubsets(vector<vector<int>>& all_sols, vector<int>& sol, vector<int> nums) {
        for (size_t i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i-1]) {
                // skip duplicates number for deduplication
                continue;
            }
            // pick one number
            sol.push_back(nums[i]);
            all_sols.push_back(sol);
            // construct a new vector
            vector<int> new_nums(nums.size()-i-1, 0);
            for (size_t j = i+1; j < nums.size(); ++j) {
                new_nums.at(j-i-1) = nums[j];
            }
            // recursion
            findSubsets(all_sols, sol, new_nums);
            // roll back
            sol.pop_back();
        }
    }
};

int main() {
    Solution obj;
    auto run = [&](vector<int> nums) {
        auto ans = obj.subsetsWithDup(nums);
        for (auto &vec : ans) {
            for (auto &n : vec) {
                cout << n << " ";
            }
            cout << endl;
        }
    };
    run({1, 2, 2});
    return 0;
}
