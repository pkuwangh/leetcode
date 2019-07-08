/**
 * You are a professional robber planning to rob houses along a street.
 * Each house has a certain amount of money stashed.
 * All houses at this place are arranged in a circle.
 * That means the first house is the neighbor of the last one.
 * Meanwhile, adjacent houses have security system connected and it will automatically
 * contact the police if two adjacent houses were broken into on the same night.
 * 
 * Given a list of non-negative integers representing the amount of money of each house,
 * determine the maximum amount of money you can rob tonight without alerting the police.
 * Example 1:
 * Input: [2,3,2]
 * Output: 3
 * Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2),
 *              because they are adjacent houses.
 * Example 2:
 * Input: [1,2,3,1]
 * Output: 4
 * Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
 *              Total amount you can rob = 1 + 3 = 4.
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        // option 1: take first house
        int op1 = nums[0] + rob(nums, 2, nums.size()-1);
        // option 2: do not take first house
        int op2 = rob(nums, 1, nums.size());
        return max(op1, op2);
    }

    int rob(vector<int>& nums, int start, int end) {
        // starting from a certain point, without considering the circle
        // dp[i+2] represent max amount till nums[i]
        vector<int> dp(end+2, 0);
        for (int i = start; i < end; ++i) {
            dp[i+2] = max(dp[i] + nums[i], dp[i+1]);
        }
        return dp[end + 1];
    }
};

int main() {
    Solution obj;
    auto run = [&](vector<int> nums)->void {
        for_each(nums.begin(), nums.end(), [](int& n)->void { cout << n << " "; });
        cout << endl;
        cout << obj.rob(nums) << endl;
    };
    run({});
    run({7});
    run({2, 3, 2});
    run({1, 2, 3, 1});
    return 0;
}
