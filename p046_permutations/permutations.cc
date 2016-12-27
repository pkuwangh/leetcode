/* Given a collection of distinct numbers, return all possible permutations.
 *
 * For example,
 * [1,2,3] have the following permutations:
 * [
 *   [1,2,3],
 *   [1,3,2],
 *   [2,1,3],
 *   [2,3,1],
 *   [3,1,2],
 *   [3,2,1]
 * ]
 */

#include <vector>
#include <iostream>
using namespace std;

class Solution {
  public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> all_sols;
        vector<int> sol;
        findPermutation(all_sols, sol, nums);
        return all_sols;
    }

    void findPermutation(vector<vector<int>>& all_sols, vector<int>& sol, vector<int>& nums)
    {
        int size = nums.size();
        if (size == 1) {
            // find a permutation
            sol.push_back(nums[0]);
            all_sols.push_back(sol);
            // roll back
            sol.pop_back();
            return;
        }
        // create a new vector of numbers with remaining candidates
        vector<int> nums_rest(size-1, 0);
        for (int i = 0; i < size; ++i) {
            sol.push_back(nums[i]);
            // construct the new vector
            for (int k = 0; k < size-1; ++k) {
                nums_rest[k] = nums[k];
            }
            if (i < size-1) {
                nums_rest.at(i) = nums.at(size-1);
            }
            // recursion
            findPermutation(all_sols, sol, nums_rest);
            // roll back
            sol.pop_back();
        }
    }
};

int main() {
    Solution obj;
    auto run = [&](vector<int> nums)->void {
        auto ans = obj.permute(nums);
        for (auto & permutation : ans) {
            for (auto & n : permutation) {
                cout << n << " ";
            }
            cout << endl;
        }
    };
    run({1, 2, 3});
    return 0;
}
