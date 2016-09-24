/* Given a set of non-overlapping intervals,
 * insert a new interval into the intervals (merge if necessary).
 *
 * You may assume that the intervals were initially sorted according to their start times.
 *
 * Example 1:
 * Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
 *
 * Example 2:
 * Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
 *
 * This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
 */

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

#define DEBUG

// Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};


class Solution {
  public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        int start = newInterval.start;;
        int end = newInterval.end;

        bool merging = false;
        bool merged = false;

        for (int i = 0; i < (int)intervals.size(); ++i) {
            if (merging) {
                if (intervals[i].start <= end) {
                    // merging continues, update end if necessary
                    if (end < intervals[i].end) end = intervals[i].end;
                    continue;
                } else {
                    // merging compltes
                    merging = false;
                    merged = true;
                    res.push_back(Interval(start, end));
                }
            } else {
                if (!merged) {
                    if (intervals[i].start <= end && intervals[i].end >= start) {
                        // merging begins
                        merging = true;
                        if (start > intervals[i].start) start = intervals[i].start;
                        if (end < intervals[i].end) end = intervals[i].end;
                        continue;
                    }
                    if (intervals[i].start > end) {
                        // no merging, added in directly
                        res.push_back(Interval(start, end));
                        merged = true;
                    }
                }
            }
            res.push_back(intervals[i]);
        }

        if (!merged) res.push_back(Interval(start, end));

#ifdef DEBUG
        for_each(res.begin(), res.end(), [](Interval &interval)->void {
                cout << "[" << interval.start << ", " << interval.end << "]" << endl; });
        cout << endl;
#endif
        return res;
    }
};

int main() {
    Solution obj;

    vector<Interval> intervals;
    intervals.push_back(Interval(1, 2));
    intervals.push_back(Interval(3, 5));
    intervals.push_back(Interval(6, 7));
    intervals.push_back(Interval(8, 10));
    intervals.push_back(Interval(12, 16));
    intervals.push_back(Interval(20, 26));

    obj.insert(intervals, Interval(4, 9));

    intervals.clear();
    intervals.push_back(Interval(4, 5));

    obj.insert(intervals, Interval(1, 7));

    return 0;
}
