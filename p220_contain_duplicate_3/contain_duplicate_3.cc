/* Given an array of integers, find out whether there are two distinct indices i and j in the array
 * such that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.
 * Example 1:
 * Input: nums = [1,2,3,1], k = 3, t = 0
 * Output: true
 * 
 * Example 2:
 * Input: nums = [1,0,1,1], k = 1, t = 2
 * Output: true
 * 
 * Example 3:
 * Input: nums = [1,5,9,1,5,9], k = 2, t = 3
 * Output: false
 */

#include <vector>
#include <cstdint>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
  public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        // use a sliding window (size k+1) to satisfy k
        // keep a sorted view, i.e. map within the window, easy to check t
        if (t < 0) return false;
        set<int64_t> hm;
        for (int i = 0; i < nums.size(); ++i) {
            // slide the window
            if (i > k) {
                hm.erase(nums[i-k-1]);
            }
            // insert into map
            if (hm.count(nums[i]) > 0) {
                return true;
            } else {
                auto ret = hm.insert(nums[i]);
                auto iter = ret.first;
                if (iter != begin(hm) && (*iter - *prev(iter)) <= t) {
                    return true;
                }
                if (next(iter) != end(hm) && (*next(iter) - *iter) <= t) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution obj;
    auto run = [&](vector<int> nums, int k, int t)->void {
        cout << obj.containsNearbyAlmostDuplicate(nums, k, t) << endl;
    };
    run({1,2,3,1}, 3, 0);
    run({1,0,1,1}, 1, 2);
    run({1,5,9,1,5,9}, 2, 3);
    run({0,2147483647}, 1, 2147483647);
    run({-1,2147483647}, 1, 2147483647);
    return 0;
}
