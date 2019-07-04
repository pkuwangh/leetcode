/* Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array
 * such that nums[i] = nums[j] and the absolute difference between i and j is at most k.
 * Example 1:
 * Input: nums = [1,2,3,1], k = 3
 * Output: true
 * 
 * Example 2:
 * Input: nums = [1,0,1,1], k = 1
 * Output: true
 * 
 * Example 3:
 * Input: nums = [1,2,3,1,2,3], k = 2
 * Output: false
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
  public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> hm;
        for (int i = 0; i < nums.size(); ++i) {
            if (hm.count(nums[i]) > 0) {
                // hit, check index diff
                if (i - hm[nums[i]] <= k) {
                    return true;
                } else {
                    // update index
                    hm[nums[i]] = i;
                }
            } else {
                hm[nums[i]] = i;
            }
        }
        return false;
    }
};

int main() {
    Solution obj;
    auto run = [&](vector<int> nums, int k)->void {
        cout << obj.containsNearbyDuplicate(nums, k) << endl;
    };
    run({1, 2, 3, 1}, 3);
    run({1, 0, 1, 1}, 1);
    run({1, 2, 3, 1, 2, 3}, 2);
    return 0;
}
