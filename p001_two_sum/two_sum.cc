/*
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 * You may assume that each input would have exactly one solution.
 * 
 * Example:
 * Given nums = [2, 7, 11, 15], target = 9,
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 */

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// build a hash table
// key is the required pair number
// value is the index
class Solution {
  public:
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> indices(2, 0);
        map<int, int> hash_table;

        for (int index = 0; index < (int)(nums.size()); ++index) {
            int num = nums[index];
            int pair_num = target - num;
            if (hash_table.count(pair_num) != 0) {
                indices[0] = hash_table[pair_num];
                indices[1] = index;
                break;
            } else {
                hash_table[num] = index;
            }
        }
        return indices;
    }
};

int main() {
    vector<int> nums = {2, 7, 11, 15};

    auto printElement = [](int &n)->void { cout << n << " "; };

    for_each(nums.begin(), nums.end(), printElement);
    cout << endl;

    Solution obj;

    auto printSolution = [&](int target)->void {
        cout << target << ":";
        auto indices = obj.twoSum(nums, target);
        for_each(indices.begin(), indices.end(), printElement);
        cout << endl;
    };

    vector<int> targets = {9, 13, 18, 26};
    for_each(targets.begin(), targets.end(), printSolution);

    return 0;
}
