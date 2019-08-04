/**
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.
 * Each element in the array represents your maximum jump length at that position.
 * Your goal is to reach the last index in the minimum number of jumps.
 * Example:
 * Input: [2,3,1,1,4]
 * Output: 2
 * Explanation: The minimum number of jumps to reach the last index is 2.
 *     Jump 1 step from index 0 to 1, then 3 steps to the last index.
 */

#include <cassert>
#include <cstdint>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <list>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <functional>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int jump(vector<int>& nums) {
        int cur_max = 0;
        int last_max = 0;
        int num_jumps = 0;
        while (cur_max < nums.size()-1) {
            int old_last_max = last_max;
            last_max = cur_max;
            for (int idx = old_last_max; idx <= last_max; ++idx) {
                // try from any point last jump can cover
                cur_max = max(idx + nums[idx], cur_max);
            }
            ++ num_jumps;
            if (cur_max == last_max) {
                // cannot extend
                return -1;
            }
        }
        return num_jumps;
    }
    /*
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), nums.size());
        dp[0] = 0;
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (j + nums[j] >= i) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
        return dp[nums.size()-1];
    }
    */
};

int main() {
    Solution obj;
    auto run = [&](vector<int> nums) ->void {
        cout << obj.jump(nums) << endl;
    };
    run({2,3,1,1,4});
    return 0;
}
