/*
 * Given an unsorted integer array, find the smallest missing positive integer.
 * 
 * Example 1:
 * Input: [1,2,0]
 * Output: 3
 * 
 * Example 2:
 * Input: [3,4,-1,1]
 * Output: 2
 * 
 * Example 3:
 * Input: [7,8,9,11,12]
 * Output: 1
 * 
 * Note:
 * Your algorithm should run in O(n) time and uses constant extra space.
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // using non-constant space; use a hash table
        /*
        int fmp = 1;
        unordered_set<int> num_set;
        for (auto& n : nums) {
            num_set.insert(n);
            while (num_set.count(fmp) > 0) {
                ++ fmp;
            }
        }
        return fmp;
        */

        // in-place; use the vector as a hash table?
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] > 0 && nums[i] <= nums.size() && nums[nums[i]-1] != nums[i]) {
                swap(nums[nums[i]-1], nums[i]);
            } else {
                ++ i;
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i+1) {
                return i+1;
            }
        }
        return nums.size() + 1;
    }
};

int main() {
    Solution obj;
    auto run_test = [&obj](vector<int> nums) -> void {
        cout << "[ ";
        for_each(nums.begin(), nums.end(), [](int& n)->void { cout << n << " "; });
        cout << "]: ";
        cout << obj.firstMissingPositive(nums) << endl;
    };

    run_test({});
    run_test({1});
    run_test({1, 2, 0});
    run_test({3, 4, -1, 1});
    run_test({7, 8, 9, 11, 12});
    run_test({2, 8, 3, 5, 1});

    return 0;
}
