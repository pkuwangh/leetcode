/*
 * Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
 * (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
 * Find the minimum element.
 * You may assume no duplicate exists in the array.
 * Example 1:
 * Input: [3,4,5,1,2] 
 * Output: 1
 * 
 * Example 2:
 * Input: [4,5,6,7,0,1,2]
 * Output: 0
 */

#include <vector>
#include <iostream>
using namespace std;

class Solution {
  public:
    int findMin(vector<int>& nums) {
        return findMinBinarySearch(nums, 0, nums.size()-1);
    }
    int findMinBinarySearch(vector<int>& nums, unsigned low, unsigned high) {
        if (low == high) {
            return nums[low];
        } else {
            if (nums[low] < nums[high]) {
                // in order
                return nums[low];
            } else {
                unsigned mid = (low + high) / 2;
                if (nums[low] > nums[mid]) {
                    // pivot in lower part
                    return findMinBinarySearch(nums, low, mid);
                } else {
                    return findMinBinarySearch(nums, mid+1, high);
                }
            }
        }
    }
};

int main() {
    Solution obj;
    auto run = [&obj](vector<int> nums)->void {
        cout << obj.findMin(nums) << std::endl;
    };
    run({3, 4, 5, 1, 2});
    run({4, 5, 6, 7, 0, 1, 2});
    return 0;
}
