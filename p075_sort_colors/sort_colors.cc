/* Given an array with n objects colored red, white or blue,
 * sort them so that objects of the same color are adjacent,
 * with the colors in the order red, white and blue.
 *
 * Here, we will use the integers 0, 1, and 2 to represent
 * the color red, white, and blue respectively.
 *
 * Follow up:
 * Could you come up with an one-pass algorithm using only constant space?
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    void sortColors(vector<int>& nums) {
        // 2-pass
#if 0
        vector<int> count(3, 0);
        for (auto &n : nums) {
            ++ count[n];
        }
        for (int i = 0; i < count[0]; ++i) nums[i] = 0;
        for (int i = 0; i < count[1]; ++i) nums[count[0]+i] = 1;
        for (int i = 0; i < count[2]; ++i) nums[count[0]+count[1]+i] = 2;
#endif

        // 1-pass: two pointers
        int low = 0;
        int high = nums.size()-1;
        int i = 0;
        while (i <= high) {
            if (nums[i] == 0) {
                swap(nums[i], nums[low++]);
                if (i < low) i = low;
            } else if (nums[i] == 1) {
                ++ i;
            } else {
                swap(nums[i], nums[high--]);
            }
        }
    }
};

int main() {
    Solution obj;
    auto run = [&](vector<int> nums)->void {
        obj.sortColors(nums);
        for_each(nums.begin(), nums.end(), [](int& n) { cout << n << " "; });
        cout << endl;
    };
    run({1, 2, 0, 2, 0, 1, 1, 1, 0});
    run({2, 1, 2});
    run({0});
    run({0, 1});
    return 0;
}
