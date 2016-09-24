/* Given a collection of intervals, merge all overlapping intervals.
 *
 * For example,
 * Given [1,3],[2,6],[8,10],[15,18],
 * return [1,6],[8,10],[15,18].
 */

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define DEBUG

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
  public:
    vector<Interval> merge(vector<Interval>& intervals) {
#ifdef DEBUG
        auto print_intervals = [](vector<Interval>& intervals) {
            for (auto & interval : intervals) {
                cout << "[" << interval.start << ", " << interval.end << "]" << endl;
            }
        };

        cout << "Input intervals..." << endl;
        print_intervals(intervals);
#endif

        sort(intervals.begin(), intervals.end(),
                [](const Interval &a, const Interval &b)->bool {
                return a.start < b.start; });

#ifdef DEBUG
        cout << "Sorted input intervals..." << endl;
        print_intervals(intervals);
#endif

        vector<Interval> merged_intervals;

        bool merging = false;
        int start = 0;
        int end = 0;
        for (size_t i = 0; i < intervals.size(); ++i) {
            if (merging && intervals[i].start <= end) {
                if (end < intervals[i].end) {
                    end = intervals[i].end;
                }
            } else {
                if (merging) {
                    merged_intervals.push_back(Interval(start, end));
                }
                merging = true;
                start = intervals[i].start;
                end = intervals[i].end;
            }
        }

        if (merging) {
            merged_intervals.push_back(Interval(start, end));
        }

#ifdef DEBUG
        cout << "Onput intervals..." << endl;
        print_intervals(merged_intervals);
#endif

        return merged_intervals;
    }
};

int main() {
    Solution obj;

    vector<Interval> intervals;
//    intervals.push_back(Interval(2, 6));
//    intervals.push_back(Interval(8, 10));
//    intervals.push_back(Interval(15, 18));
//    intervals.push_back(Interval(3, 4));
//    intervals.push_back(Interval(1, 3));
//    intervals.push_back(Interval(7, 12));
   
    intervals.push_back(Interval(1, 4));
    intervals.push_back(Interval(1, 4));

    obj.merge(intervals);

    return 0;
}
