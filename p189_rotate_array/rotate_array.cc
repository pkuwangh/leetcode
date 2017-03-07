/* Rotate an array of n elements to the right by k steps.
 * For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
 * Hint:
 * Could you do it in-place with O(1) extra space?
 */

#include <vector>
#include <iostream>
using namespace std;

class Solution {
  public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int idx = 0;
        int start_idx = 0;
        int temp = nums[idx];
        for (int i = 0; i < n; ++i) {
            int map_idx = (idx + k) % n;
            swap(temp, nums[map_idx]);
            idx = map_idx;
            if (idx == start_idx) {
                // reset
                ++idx;
                start_idx = idx;
                temp = nums[idx];
            }
        }
    }
};

int main() {
    Solution obj;
    auto run = [&obj](vector<int> nums, int k)->void {
        obj.rotate(nums, k);
        for (auto &n : nums) { cout << n << " "; }
        cout << endl;
    };
    run({1,2,3,4,5,6,7}, 3);
    run({1,2,3,4,5,6}, 2);
    run({1}, 0);
    run({1, 2}, 1);
    return 0;
}
