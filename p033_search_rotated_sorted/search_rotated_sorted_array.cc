/* Suppose an array sorted in ascending order is rotated at some pivot
 * unknown to you beforehand.
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 * You are given a target value to search.
 * If found in the array return its index, otherwise return -1.
 * You may assume no duplicate exists in the array.
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int search(vector<int>& nums, int target) {
        return searchArray(nums, 0, nums.size()-1, target);
    }

    int searchArray(vector<int>& nums, int low, int high, int &target) {
        if (low > high) return -1;
        int mid = (low + high)/2;
        if (nums[mid] == target) return mid;
        if (nums[mid] < nums[high]) {
            // right half is sorted
            if (target > nums[mid] && target <= nums[high])
                return searchArray(nums, mid+1, high, target);
            else
                return searchArray(nums, low, mid-1, target);
        } else {
            // left half is sorted
            if (target < nums[mid] && target >= nums[low])
                return searchArray(nums, low, mid-1, target);
            else
                return searchArray(nums, mid+1, high, target);
        }
    }
};

int main() {
    Solution obj;
    auto run = [&](vector<int> nums, int target) {
        cout << obj.search(nums, target) << endl;
    };
    run({4, 5, 6, 7, 0, 1, 2}, 1);
    return 0;
}
