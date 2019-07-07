/* 300. Longest Increasing Subsequence
 * Given an unsorted array of integers, find the length of longest increasing subsequence.
 * Example:
 * Input: [10,9,2,5,3,7,101,18]
 * Output: 4 
 * Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 
 * Note:
 * 
 * There may be more than one LIS combination, it is only necessary for you to return the length.
 * Your algorithm should run in O(n2) complexity.
 * Follow up: Could you improve it to O(n log n) time complexity?
*/

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int lengthOfLIS(vector<int>& nums) {
        // classic 1-D dynamic programming
        const int len = nums.size();
        if (len == 0) return 0;
        // dp[i] represent the LIS ending in nums[i]
        vector<int> dp(len, 0);
        // inittialize
        dp[0] = 1;
        // dp[i] = max(1, dp[j]+1 for 0<=j<i,a[j]<a[i])
        int lis = 1;
        for (int i = 1; i < len; ++i) {
            dp[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (dp[i] < dp[j] + 1 && nums[j] < nums[i]) {
                    dp[i] = dp[j] + 1;
                }
            }
            if (lis < dp[i]) {
                lis = dp[i];
            }
        }
        // final result
        return lis;
    }
};

int main() {
    Solution obj;
    auto run = [&](vector<int> nums)->void {
        for_each(nums.begin(), nums.end(), [](int& x)->void { cout << x << " "; });
        cout << endl;
        cout << obj.lengthOfLIS(nums) << endl;
    };
    run({10,9,2,5,3,7,101,18});
    run({});
    return 0;
}
