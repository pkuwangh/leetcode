/**
 * Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
 * Example:
 * Input: [0,1,0,3,12]
 * Output: [1,3,12,0,0]
 * Note:
 * You must do this in-place without making a copy of the array.
 * Minimize the total number of operations.
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
    void moveZeroes(vector<int>& nums) {
        int ptr_z = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                // encountered a zero
                if (nums[ptr_z] != 0) {
                    ptr_z = i;
                }
            } else {
                if (nums[ptr_z] == 0) {
                    swap(nums[ptr_z], nums[i]);
                    ++ ptr_z;
                }
            }
        }
    }
};

int main() {
    Solution obj;
    auto run = [&](vector<int> nums) ->void {
        for (auto& n : nums) {
            cout << n << " ";
        }
        cout << endl;
        obj.moveZeroes(nums);
        for (auto& n : nums) {
            cout << n << " ";
        }
        cout << endl;
    };
    run({0,1,0,3,12});
    return 0;
}
