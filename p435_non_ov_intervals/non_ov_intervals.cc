/** Given a collection of intervals, find the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.
 * Note:
 * You may assume the interval's end point is always bigger than its start point.
 * Intervals like [1,2] and [2,3] have borders "touching" but they don't overlap each other.
 * Example 1:
 * Input: [ [1,2], [2,3], [3,4], [1,3] ]
 * Output: 1
 * Explanation: [1,3] can be removed and the rest of intervals are non-overlapping.
 * Example 2:
 * Input: [ [1,2], [1,2], [1,2] ]
 * Output: 2
 * Explanation: You need to remove two [1,2] to make the rest of intervals non-overlapping.
 * Example 3:
 * Input: [ [1,2], [2,3] ]
 * Output: 0
 * Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
 * NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.
 */

#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>
using namespace std;

class Solution {
  public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // sort based on starting point
        sort(intervals.begin(), intervals.end(), [](const vector<int>& e1, const vector<int>& e2)->bool { return e1[0] < e2[0]; });
        int num_erase = 0;
        int right_stretch = INT_MIN;
        for (const auto& x : intervals) {
            if (x[0] < right_stretch) {
                ++ num_erase;
                right_stretch = min(right_stretch, x[1]);
            } else {
                right_stretch = x[1];
            }
        }
        return num_erase;
    }
};

int main() {
    Solution obj;
    auto run = [&](vector<vector<int>> intervals)->void {
        for (auto& x : intervals) {
            cout << "[" << x[0] << ", " << x[1] << "] ";
        }
        cout << endl;
        cout << obj.eraseOverlapIntervals(intervals) << endl;
    };
    run({{1,2},{2,3},{3,4},{1,3}});
    run({{1,2},{1,2},{1,2}});
    run({{1,2},{2,3}});
    return 0;
}
