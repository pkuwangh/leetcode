/* Implement next permutation, which rearranges numbers into the
 * lexicographically next greater permutation of numbers.
 *
 * If such arrangement is not possible, it must rearrange it as the
 * lowest possible order (ie, sorted in ascending order).
 *
 * The replacement must be in-place, do not allocate extra memory.
 *
 * Here are some examples. Inputs are in the left-hand column and
 * its corresponding outputs are in the right-hand column.
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        // from the right, find first desceneding order
        int p = -1;
        // nums[p] < nums[p+1]
        // nums[p+1 : size-1] is the maximum combination
        for (int i = size-1; i > 0; --i) {
            if (nums[i-1] < nums[i]) {
                p = i - 1;
                break;
            }
        }
        // in nums[p+1 : size-1], find the q such that nums[q] just larger than nums[p]
        int q = size-1;
        for (int i = p+1; i < size; ++i) {
            if (nums[i] <= nums[p]) {
                q = i - 1;
                break;
            }
        }
        // swap p and q
        if (p >= 0) {
            swap (nums[p], nums[q]);
        }
        // reverse nums[p+1 : size-1]
        int l = p+1;
        int r = size-1;
        while (l < r) {
            swap(nums[l], nums[r]);
            ++l;
            --r;
        }
    }
};

int main() {
    Solution obj;

    auto check = [&](vector<int> nums)->void {
        for_each(nums.begin(), nums.end(), [](int n) { cout << n << " "; });
        cout << "-->> ";
        obj.nextPermutation(nums);
        for_each(nums.begin(), nums.end(), [](int n) { cout << n << " "; });
        cout << endl;
    };

    check({1, 2, 3});
    check({1, 3, 2});
    check({1, 1, 5});
    check({1, 5, 1});

    return 0;
}
