/**
 * Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
 * Note: The algorithm should run in linear time and in O(1) space.
 * Example 1:
 * Input: [3,2,3]
 * Output: [3]
 * Example 2:
 * Input: [1,1,1,3,3,2,2,2]
 * Output: [1,2]
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int candidate1 = 0;
        int candidate2 = 0;
        int count1 = 0;
        int count2 = 0;
        for (const auto& x : nums) {
            if (count1 > 0 && candidate1 == x) {
                ++ count1;
            } else if (count2 > 0 && candidate2 == x) {
                ++ count2;
            } else if (count1 == 0) {
                count1 = 1;
                candidate1 = x;
            } else if (count2 == 0) {
                count2 = 1;
                candidate2 = x;
            } else {
                -- count1;
                -- count2;
            }
        }
        // verify
        count1 = 0;
        count2 = 0;
        int size = nums.size();
        for (const auto& x : nums) {
            if (x == candidate1) {
                ++ count1;
            } else if (x == candidate2) {
                ++ count2;
            }
        }
        if (count1 > size/3) ans.emplace_back(candidate1);
        if (count2 > size/3) ans.emplace_back(candidate2);
        return ans;
    }
};

int main() {
    Solution obj;
    auto run = [&](vector<int> nums)->void {
        auto print = [](int& n)->void { cout << n << " "; };
        for_each(nums.begin(), nums.end(), print);
        cout << endl;
        auto ans = obj.majorityElement(nums);
        for_each(ans.begin(), ans.end(), print);
        cout << endl;
    };
    run({3,2,3});
    run({1,1,1,3,3,2,2,2});
}
