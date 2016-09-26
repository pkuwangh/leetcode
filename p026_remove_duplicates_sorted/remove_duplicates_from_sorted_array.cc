/* Given a sorted array, remove the duplicates in place such that
 * each element appear only once and return the new length.
 *
 * Do not allocate extra space for another array, you must do this in place with constant memory.
 *
 * For example,
 * Given input array nums = [1,1,2],
 *
 * Your function should return length = 2,
 * with the first two elements of nums being 1 and 2 respectively.
 * It doesn't matter what you leave beyond the new length.
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if (size < 2) return size;
        int end = 0;
        for (int i = 1; i < size; ++i) {
            if (nums[end] != nums[i]) {
                ++ end;
                nums[end] = nums[i];
            }
        }
        return end+1;
    }

#if 0
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) {
            return 0;
        }
        int last = nums[size - 1];
        // change the duplicates to biggest value
        for (int i = 0; i < size - 1; ++i) {
            int j = i + 1;
            while (j < size && nums[j] == nums[i]) {
                nums[j] = last;
                ++j;
            }
        }
        // sort again
        sort(nums.begin(), nums.end(), [](const int &a, const int &b)->bool { return a < b; });
        // get the correct length
        for (int i = 0; i < size; ++i) {
            int j = i + 1;
            if (j == size || nums[j] == nums[i]) {
                return j;
            }
        }
        return 0;
    }
#endif
};

int main() {
    Solution obj;
    auto run = [&](vector<int> nums) ->void {
        cout << obj.removeDuplicates(nums) << endl;
    };

    run({});
    run({1, 2, 3});
    run({1, 1, 2});
    run({1, 1, 2, 2, 3, 3, 4});
    return 0;
}
