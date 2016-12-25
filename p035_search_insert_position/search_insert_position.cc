/* Given a sorted array and a target value, return the index if the target is found.
 * If not, return the index where it would be if it were inserted in order.
 *
 * You may assume no duplicates in the array.
 *
 * Here are few examples.
 * [1,3,5,6], 5 → 2
 * [1,3,5,6], 2 → 1
 * [1,3,5,6], 7 → 4
 * [1,3,5,6], 0 → 0
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int searchInsert(vector<int>& nums, int target) {
        return binary_search(nums, target, 0, nums.size()-1);
    }

    int binary_search(vector<int>& nums, int target, int low, int high) {
        if (low > high) {
            return low;
        }
        int mid = (low + high) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            // search upper half
            return binary_search(nums, target, mid+1, high);
        } else {
            // search lower half
            return binary_search(nums, target, low, mid-1);
        }
        return -1;
    }
};

int main() {
    Solution obj;
    auto run = [&](vector<int> nums, int target) -> void {
        cout << "[ ";
        for_each(nums.begin(), nums.end(), [](int &n) -> void { cout << n << " "; });
        cout << "]";
        auto ans = obj.searchInsert(nums, target);
        cout << ", " << target << " -> " << ans << endl;
    };

    run({1, 3, 5, 6}, 5);
    run({1, 3, 5, 6}, 2);
    run({1, 3, 5, 6}, 7);
    run({1, 3, 5, 6}, 0);
    return 0;
}
