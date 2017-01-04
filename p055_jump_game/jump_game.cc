/* Given an array of non-negative integers,
 * you are initially positioned at the first index of the array.
 * Each element in the array represents your maximum jump length at that position.
 * Determine if you are able to reach the last index.
 * For example:
 * A = [2,3,1,1,4], return true.
 * A = [3,2,1,0,4], return false.
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Time Limit Exceeded with simple DFS
// Still Time Limit Exceeded with simple DP
class Solution {
  public:
#if 0
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return false;
        int left = size - 1;
        for (int i = size-2; i >= 0; --i) {
            if (i+nums[i] >= left) {
                left = i;
            }
        }
        return (left == 0);
    }
#endif
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        int maxIndex = 0;
        for (int i = 0; i < size-1; ++i) {
            if (i > maxIndex) break;
            maxIndex = max(maxIndex, i+nums[i]);
        }
        return (maxIndex >= size-1);
    }
};

int main() {
    Solution obj;
    auto run = [&](vector<int> nums) { cout << obj.canJump(nums) << endl; };
    run({2, 3, 1, 1, 4});
    run({3, 2, 1, 0, 4});
    return 0;
}
