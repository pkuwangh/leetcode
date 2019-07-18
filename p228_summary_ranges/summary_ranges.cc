/**
 * Given a sorted integer array without duplicates, return the summary of its ranges.
 * Example 1:
 * Input:  [0,1,2,4,5,7]
 * Output: ["0->2","4->5","7"]
 * Explanation: 0,1,2 form a continuous range; 4,5 form a continuous range.
 * Example 2:
 * Input:  [0,2,3,4,6,8,9]
 * Output: ["0","2->4","6","8->9"]
 * Explanation: 2,3,4 form a continuous range; 8,9 form a continuous range.
 */

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ranges;
        if (nums.size() > 0) {
            int start = nums[0];
            for (unsigned i = 0; i < nums.size(); ++i) {
                if (i == nums.size() -1 || nums[i] + 1 != nums[i+1]) {
                    // range stops at i-1
                    if (start < nums[i]) {
                        ranges.emplace_back(to_string(start) + "->" + to_string(nums[i]));
                    } else {
                        ranges.emplace_back(to_string(nums[i]));
                    }
                    if (i + 1 < nums.size()) {
                        start = nums[i+1];
                    }
                }
            }
        }
        return ranges;
    }
};

int main() {
    Solution obj;
    auto run = [&](vector<int> nums)->void {
        for_each(nums.begin(), nums.end(), [](int& x)->void { cout << x << " "; });
        cout << endl;
        auto ans = obj.summaryRanges(nums);
        for_each(ans.begin(), ans.end(), [](string& x)->void { cout << x << " "; });
        cout << endl;
    };
    run({0,1,2,4,5,7});
    run({0,2,3,4,6,8,9});
    run({8});
    return 0;
}
