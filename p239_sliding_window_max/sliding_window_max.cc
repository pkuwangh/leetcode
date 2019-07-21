/**
 * Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right.
 * You can only see the k numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window.
 * Example:
 * Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
 * Output: [3,3,5,5,6,7] 
 * Explanation: 
 * Window position                Max
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 *  1 [3  -1  -3] 5  3  6  7       3
 *  1  3 [-1  -3  5] 3  6  7       5
 *  1  3  -1 [-3  5  3] 6  7       5
 *  1  3  -1  -3 [5  3  6] 7       6
 *  1  3  -1  -3  5 [3  6  7]      7
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ input array's size for non-empty array.
 * Follow up:
 * Could you solve it in linear time?
 */

#include <cassert>
#include <cstdint>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <list>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <algorithm>
using namespace std;

class Solution {
  public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> ans;

        for (int i = 0; i < nums.size(); ++i) {
            while (!q.empty() && nums[i] > q.back()) q.pop_back();
            q.push_back(nums[i]);
            const int s = i - k + 1;
            if (s < 0) continue;
            ans.push_back(q.front());
            if (nums[s] == q.front()) q.pop_front();
        }
        return ans;
    }
};

int main() {
    Solution obj;
    auto run = [&](vector<int> nums, int k) ->void {
        cout << "[ ";
        for (auto& x : nums) {
            cout << x << " ";
        }
        cout << "] k=" << k << endl;
        auto ans = obj.maxSlidingWindow(nums, k);
        for (auto& x : ans) {
            cout << x << " ";
        }
        cout << endl;
    };
    run({1,3,-1,-3,5,3,6,7}, 3);
    run({1,-1}, 1);
    return 0;
}
