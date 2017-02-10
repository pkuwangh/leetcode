/* Given an array of size n, find the majority element.
 * The majority element is the element that appears more than ⌊ n/2 ⌋ times.
 * You may assume that the array is non-empty and the majority element always exist in the array.
 */

#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
  public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> num_map;
        for (auto &num : nums) {
            if (num_map.count(num) > 0) {
                ++num_map[num];
            } else {
                num_map[num] = 1;
            }
        }
        for (auto iter = num_map.begin(); iter != num_map.end(); ++iter) {
            if (iter->second > n/2) {
                return iter->first;
            }
        }
        return -1;
    }
};

int main() {
    Solution obj;
    auto run = [&obj](vector<int> nums)->void { cout << obj.majorityElement(nums) << endl; };
    run({1, 2, 3, 2, 2, 4, 2});
    run({3, 2, 3});
    return 0;
}
