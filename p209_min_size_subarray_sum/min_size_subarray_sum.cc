/* Given an array of n positive integers and a positive integer s,
 * find the minimal length of a contiguous subarray of which the sum ≥ s.
 * If there isn't one, return 0 instead.
 * For example, given the array [2,3,1,2,4,3] and s = 7,
 * the subarray [4,3] has the minimal length under the problem constraint.
 */

#include <vector>
#include <iostream>
using namespace std;

class Solution {
  public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return 0;

        int min_len = 0;
        int left = 0;
        int sum = 0;
        for (int right = 0; right < size; ++right) {
            sum += nums[right];
            // move left pointer towards right
            while (sum - nums[left] >= s) {
                sum -= nums[left];
                ++ left;
            }
            // check if sum meets constraint
            if (sum >= s) {
                int len = right - left + 1;
                if (min_len == 0 || min_len > len) {
                    min_len = len;
                }
            }
        }
        return min_len;
    }
};

int main() {
    Solution obj;
    auto run = [&obj](int s, vector<int> nums)->void {
        cout << obj.minSubArrayLen(s, nums) << endl;
    };
    run(7, {2, 3, 1, 2, 4, 3});
    return 0;
}
