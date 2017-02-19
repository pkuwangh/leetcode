/* A peak element is an element that is greater than its neighbors.
 * Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.
 * The array may contain multiple peaks,
 * in that case return the index to any one of the peaks is fine.
 * You may imagine that num[-1] = num[n] = -∞.
 * For example, in array [1, 2, 3, 1],
 * 3 is a peak element and your function should return the index number 2.
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int findPeakElement(vector<int>& nums) {
#if 0
        int n = nums.size();
        for (int i = 1; i <= (n+1)/2; ++i) {
            if (nums[i] < nums[i-1]) {
                return i-1;
            }
            if (nums[n-1-i] < nums[n-i]) {
                return n-i;
            }
        }
        return 0;
#endif
        int left = 0, right = nums.size()-1;
        while (left+1 < right) {
            int mid = (left+right)/2;
            if (nums[mid] < nums[mid-1]) {
                right = mid;
            } else if (nums[mid] < nums[mid+1]) {
                left = mid;
            } else {
                return mid;
            }
        }
        int peak = (nums[left] > nums[right])? left : right;
        return peak;
    }
};

int main() {
    Solution obj;
    vector<int> nums({1, 2, 3, 1});
    cout << obj.findPeakElement(nums) << endl;
    return 0;
}
