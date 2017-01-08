/* Given a set of distinct integers, nums, return all possible subsets.
 * Note: The solution set must not contain duplicate subsets.
 * For example,
 * If nums = [1,2,3], a solution is:
 * [
 *   [3],
 *   [1],
 *   [2],
 *   [1,2,3],
 *   [1,3],
 *   [2,3],
 *   [1,2],
 *   []
 * ]
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> all_sols;
        vector<int> sol;
        findSubsets(all_sols, sol, nums);
        all_sols.push_back(vector<int>());
        return all_sols;
    }

    void findSubsets(vector<vector<int>>& all_sols, vector<int>& sol, vector<int>& nums) {
        size_t size = nums.size();
        for (size_t i = 0; i < size; ++i) {
            // check in
            sol.push_back(nums[i]);
            // find a solution
            all_sols.push_back(sol);
            // construct a new candidate vector
            size_t new_size = size - i - 1;
            vector<int> new_nums(new_size, 0);
            for (size_t j = 0; j < new_size; ++j) {
                new_nums[j] = nums[i+1+j];
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
        auto ans = obj.subsets(nums);
        for (auto &vec : ans) {
            for (auto &n : vec) {
                cout << n << " ";
            }
            cout << endl;
        }
    };
    run({1, 2, 3});
    return 0;
}
