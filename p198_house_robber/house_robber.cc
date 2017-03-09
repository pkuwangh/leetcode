/* You are a professional robber planning to rob houses along a street.
 * Each house has a certain amount of money stashed, the only constraint
 * stopping you from robbing each of them is that adjacent houses have
 * security system connected and it will automatically contact the police
 * if two adjacent houses were broken into on the same night.
 *
 * Given a list of non-negative integers representing the amount of money of each house,
 * determine the maximum amount of money you can rob tonight without alerting the police.
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    // DFS results in Time Limit Exceeded
#if 0
    int rob(vector<int>& nums) {
        vector<int> pick(nums.size(), 0);
        int cur_amount = 0;
        int max_amount = 0;
        rob(nums, pick, 0, cur_amount, max_amount);
        return max_amount;
    }

    void rob(const vector<int>& nums, vector<int>& pick, uint32_t idx,
             int& cur_amount, int& max_amount)
    {
        if (idx == nums.size()) {
            // reach a possible solution
            max_amount = max(max_amount, cur_amount);
            return;
        }
        if (idx == 0 || pick[idx-1] == 0) {
            // option 1, rob idx
            pick[idx] = 1;
            cur_amount += nums[idx];
            rob(nums, pick, idx+1, cur_amount, max_amount);
            // roll back
            pick[idx] = 0;
            cur_amount -= nums[idx];
        }
        // option 2, not rob idx
        rob(nums, pick, idx+1, cur_amount, max_amount);
    }
#endif

    int rob(vector<int>& nums) {
        uint32_t n = nums.size();
        // dynamic programming
        // max_amounts[i+2] represents the max amount for rob[0:i]
        vector<int> max_amounts(n+2, 0);
        for (uint32_t i = 0; i < n; ++i) {
            uint32_t j = i+2;
            max_amounts[j] = max(max_amounts[j-2] + nums[i], max_amounts[j-1]);
        }
        return max_amounts[n+1];
    }
};

int main() {
    Solution obj;
    auto run = [&obj](vector<int> nums)->void {
        cout << obj.rob(nums) << endl;
    };
    run({1,2,5,6,3}); // 9
    run({4,1,1,3}); // 7
    return 0;
}
