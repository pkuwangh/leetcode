/* Find the contiguous subarray within an array (containing at least one number)
 * which has the largest sum.
 * For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
 * the contiguous subarray [4,-1,2,1] has the largest sum = 6.
 * More practice:
 * If you have figured out the O(n) solution,
 * try coding another solution using the divide and conquer approach, which is more subtle.
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    // dynamic programming
    // state: sum[i] represents the largest sum of a subarray ending in i
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return 0;
        vector<int> sum(size, 0);
        // initialize
        sum[0] = nums[0];
        int max_array = sum[0];
        // propagate
        for (int i = 1; i < size; ++i) {
            if (sum[i-1] < 0) {
                sum[i] = nums[i];
            } else {
                sum[i] = nums[i] + sum[i-1];
            }
            max_array = max(max_array, sum[i]);
        }
        return max_array;
    }
};

int main() {
    Solution obj;
    auto run = [&](vector<int> nums) {
        cout << obj.maxSubArray(nums) << endl;
    };
    run({-2, 1, -3, 4, -1, 2, 1, -5, 4});
    return 0;
}
