/* Given a collection of numbers that might contain duplicates,
 * return all possible unique permutations.
 *
 * For example,
 * [1,1,2] have the following unique permutations:
 * [
 *   [1,1,2],
 *   [1,2,1],
 *   [2,1,1]
 * ]
 */

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
  public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // sort first
        sort(nums.begin(), nums.end());
        // enumerate
        vector<vector<int>> all_sols;
        vector<int> sol;
        findPermutation(all_sols, sol, nums);
        return all_sols;
    }
    void findPermutation(vector<vector<int>>& all_sols, vector<int>& sol, vector<int>& nums) {
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
        // enumerate number in next position
        for (int i = 0; i < size; ++i) {
            // avoid duplicates
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            // check in number at next position
            sol.push_back(nums[i]);
            // construct the new vector
            for (int j = 0; j < i; ++j) {
                nums_rest[j] = nums[j];
            }
            for (int j = i+1; j < size; ++j) {
                nums_rest[j-1] = nums[j];
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
        auto ans = obj.permuteUnique(nums);
        for (auto & permutation : ans) {
            for (auto & n : permutation) {
                cout << n << " ";
            }
            cout << endl;
        }
    };
    run({1, 2, 3});
    run({1, 1, 2});
    return 0;
}
