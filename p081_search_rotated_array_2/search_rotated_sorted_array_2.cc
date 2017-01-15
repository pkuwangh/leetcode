/* Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 * Write a function to determine if a given target is in the array.
 * The array may contain duplicates.
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    bool search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = (low+high)/2;
            if (nums[mid] == target) return true;

            if (nums[mid] < nums[high]) {
                // right half is sorted
                if (nums[mid] < target && nums[high] >= target)
                    low = mid+1;
                else
                    high = mid-1;
            } else if (nums[mid] > nums[low]) {
                // left half is sorted
                if (nums[mid] > target && nums[low] <= target)
                    high = mid-1;
                else
                    low = mid+1;
            } else {
                if (nums[high] == target) return true;
                -- high;
            }
        }
        return false;
    }
};

int main() {
    Solution obj;
    auto run = [&](vector<int> nums, int target) {
        cout << obj.search(nums, target) << endl;
    };
    run({4, 5, 6, 2, 2, 2, 2}, 5);
    return 0;
}
