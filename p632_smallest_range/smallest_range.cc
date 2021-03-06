/**
 * You have k lists of sorted integers in ascending order.
 * Find the smallest range that includes at least one number from each of the k lists.
 * We define the range [a,b] is smaller than range [c,d] if b-a < d-c or a < c if b-a == d-c.
 * Example 1:
 * Input:[[4,10,15,24,26], [0,9,12,20], [5,18,22,30]]
 * Output: [20,24]
 * Explanation: 
 * List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
 * List 2: [0, 9, 12, 20], 20 is in range [20,24].
 * List 3: [5, 18, 22, 30], 22 is in range [20,24].
 * Note:
 * The given list may contain duplicates, so ascending order means >= here.
 * 1 <= k <= 3500
 * -10^5 <= value of elements <= 10^5.
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
#include <functional>
#include <algorithm>
using namespace std;

class Solution {
  public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // final result
        vector<int> min_range;
        // some sanity check
        if (nums.size() == 0) return min_range;
        min_range.resize(2);

        /*
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i].size() == 0) return min_range;
        }
        // have a map to pick the smallest
        multimap<int, int> curr;
        multimap<int, int> next;
        min_range[0] = nums[0][0];
        min_range[1] = nums[0][0];
        // initialize
        for (int i = 0; i < nums.size(); ++i) {
            min_range[0] = min(min_range[0], nums[i][0]);
            min_range[1] = max(min_range[1], nums[i][0]);
            curr.insert(make_pair(nums[i][0], i));
            if (nums[i].size() > 1) {
                next.insert(make_pair(nums[i][1], i));
            }
        }
        // track the index of each list
        vector<int> idx(nums.size(), 1);
        // loop until no new value to try
        while (!next.empty()) {
            // pick the smallest
            auto sit = next.begin();
            const int value = sit->first;
            const int k = sit->second;
            const int old_value = nums[k][idx[k]-1];
            // move kth list forward
            ++ idx[k];
            // remove old value from current & enqueue next
            auto eq_range = curr.equal_range(old_value);
            for (auto it = eq_range.first; it != eq_range.second; ++it) {
                if (it->second == k) {
                    curr.erase(it);
                    break;
                }
            }
            curr.insert(make_pair(value, k));
            // calculate range
            const int low = (curr.begin())->first;
            const int high = (curr.rbegin())->first;
            if (high - low < min_range[1] - min_range[0]) {
                min_range[1] = high;
                min_range[0] = low;
            }
            // prepare next
            next.erase(sit);
            if (idx[k] < nums[k].size()) {
                next.insert(make_pair(nums[k][idx[k]], k));
            }
        }
        */

        // make up a sorted array
        int size = 0;
        for (const auto& vec : nums) {
            size += vec.size();
        }
        vector<pair<int, int>> workspace(size);
        int idx = 0;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums[i].size(); ++j) {
                workspace[idx] = make_pair(nums[i][j], i);
                ++ idx;
            }
        }
        // sort it
        sort(workspace.begin(), workspace.end());
        // sliding window
        vector<int> counters(nums.size(), 0);
        // initialize
        unsigned left = 0;
        unsigned right = 0;
        counters[workspace[left].second] = 1;
        unsigned num_covers = 1;
        min_range[0] = workspace[0].first;
        min_range[1] = workspace[workspace.size()-1].first;
        if (num_covers == nums.size()) {
            min_range[1] = min_range[0];
        }
        while (right+1 < workspace.size() || num_covers == nums.size()) {
            if (num_covers < nums.size()) {
                // move right pointer
                ++ counters[workspace[right+1].second];
                if (counters[workspace[right+1].second] == 1) {
                    ++ num_covers;
                }
                ++ right;
            } else {
                // move left pointer to get smaller range
                -- counters[workspace[left].second];
                if (counters[workspace[left].second] == 0) {
                    -- num_covers;
                }
                ++ left;
            }
            if (num_covers == nums.size()) {
                // valid cover
                if (workspace[right].first - workspace[left].first < min_range[1] - min_range[0]) {
                    min_range[1] = workspace[right].first;
                    min_range[0] = workspace[left].first;
                }
            }
        }
        return min_range;
    }
};

int main() {
    Solution obj;
    auto run = [&](vector<vector<int>> nums) ->void {
        for (auto& vec : nums) {
            cout << " [ ";
            for (auto& x : vec) {
                cout << x << " ";
            }
            cout << "] ";
        }
        cout << endl;
        auto ans = obj.smallestRange(nums);
        for (auto& x : ans) {
            cout << x << " ";
        }
        cout << endl;
    };
    run({{4,10,15,24,26}, {0,9,12,20}, {5,18,22,30}});
    return 0;
}
