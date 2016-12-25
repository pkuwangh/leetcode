/* Given a sorted array of integers,
 * find the starting and ending position of a given target value.
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * If the target is not found in the array, return [-1, -1].
 * For example,
 * Given [5, 7, 7, 8, 8, 10] and target value 8,
 * return [3, 4].
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int size = nums.size();
        if (size == 0) { return vector<int>({-1, -1}); }

        int lb = size;
        int rb = -1;
        searchBound(nums, target, 0, size-1, lb, rb);
        if (rb == -1) lb = -1;
        return vector<int>({lb, rb});
    }

    void searchBound(vector<int>& nums, int target, int low, int high, int& lb, int& rb) {
        if (low > high) return;
        int mid = (low + high)/2;
        if (nums[mid] == target) {
            if (mid < lb) { lb = mid; }
            if (mid > rb) { rb = mid; }
            // keep search both left & right
            searchBound(nums, target, low, mid-1, lb, rb);
            searchBound(nums, target, mid+1, high, lb, rb);
        } else if (nums[mid] < target) {
            searchBound(nums, target, mid+1, high, lb, rb);
        } else {
            searchBound(nums, target, low, mid-1, lb, rb);
        }
    }
};

int main() {
    Solution obj;
    auto run = [&](vector<int> nums, int target)->void {
        auto ans = obj.searchRange(nums, target);
        cout << ans[0] << ", " << ans[1] << endl;
    };

    run({5, 7, 7, 8, 8, 10}, 8);
    return 0;
}
