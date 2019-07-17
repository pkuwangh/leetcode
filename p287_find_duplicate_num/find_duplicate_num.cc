/**
 * Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive),
 * prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.
 * Example 1:
 * Input: [1,3,4,2,2]
 * Output: 2
 * Example 2:
 * Input: [3,1,3,4,2]
 * Output: 3
 * Note:
 * You must not modify the array (assume the array is read only).
 * You must use only constant, O(1) extra space.
 * Your runtime complexity should be less than O(n2).
 * There is only one duplicate number in the array, but it could be repeated more than once.
*/

#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
  public:
    int findDuplicate(vector<int>& nums) {
        // we can try duplicated number from 1 to max
        // each trial involves one scan iteration O(n)
        // we can do a binary search
        int low = 1;
        int high = nums.size() - 1;
        while (low < high) {
            int med = (low + high) / 2;
            // count how many numbers lower than med
            int count = 0;
            for (const auto& x : nums) {
                if (x <= med) {
                    ++ count;
                }
            }
            if (count > med) {
                high = med;
            } else {
                low = med + 1;
            }
        }
        return low;
    }
};

int main() {
    Solution obj;
    auto run = [&](vector<int> nums)->void {
        for (auto& n : nums) {
            cout << n << " ";
        }
        cout << endl << obj.findDuplicate(nums) << endl;
    };
    run({1,3,4,2,2});
    run({3,1,3,4,2});
    run({2,2,2,2,2});
    return 0;
}
