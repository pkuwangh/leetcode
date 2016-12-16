/* Given an array S of n integers, are there elements a, b, c, and d in S
 * such that a + b + c + d = target?
 * Find all unique quadruplets in the array which gives the sum of target.
 *
 * Note: The solution set must not contain duplicate quadruplets.
 *
 * For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.
 *
 * A solution set is:
 * [
 *   [-1,  0, 0, 1],
 *   [-2, -1, 1, 2],
 *   [-2,  0, 0, 2]
 * ]
 */

#include <cassert>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
  public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end(), [](const int &a, const int &b)->bool { return a < b; });
        vector<vector<int>> all_sols;
        vector<int> sol;
        kSum(all_sols, sol, 4, nums, 0, target);
        return all_sols;
    }

    void kSum(vector<vector<int>>& all_sols, vector<int>& sol, int k,
              vector<int>& nums, int start, int target)
    {
        int end = nums.size() - 1;
        if (k == 2) {
            // two sum problem
            while (start < end) {
                int sum = nums.at(start) + nums.at(end);
                if (sum == target) {
                    // find a solution
                    sol.push_back(nums[start]);
                    sol.push_back(nums[end]);
                    all_sols.push_back(sol);
                    sol.pop_back();
                    sol.pop_back();
                    // next
                    ++ start;
                    -- end;
                    // de-duplicate
                    while (start < end && nums[start] == nums[start-1]) ++start;
                    while (end > start && nums[end] == nums[end+1]) --end;
                } else if (sum < target) {
                    ++ start;
                } else {
                    -- end;;
                }
            }
        } else {
            assert(k > 2);
            for (int i = start; i < end; ++i) {
                // de-duplicate
                if (i > start && nums.at(i) == nums.at(i-1)) continue;
                sol.push_back(nums[i]);
                kSum(all_sols, sol, k-1, nums, i+1, target-nums[i]);
                sol.pop_back();
            }
        }
    }

    vector<vector<int>> fourSumHelp(vector<int> nums, int target) {
        return fourSum(nums, target);
    }
};

int main() {
    Solution obj;
    auto ans = obj.fourSumHelp({1, 0, -1, 0, -2, 2}, 0);
    for (auto & sol : ans) {
        for (auto & n : sol) {
            cout << n << " ";
        }
        cout << endl;
    }
    return 0;
}
