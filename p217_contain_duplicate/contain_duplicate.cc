/* Given an array of integers, find if the array contains any duplicates.
 * Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
 * Example 1:
 * Input: [1,2,3,1]
 * Output: true
 * Example 2:
 * Input: [1,2,3,4]
 * Output: false
 * Example 3:
 * Input: [1,1,1,3,3,4,3,2,4,2]
 * Output: true
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
  public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> ht;
        for (const auto& n : nums) {
            if (ht.count(n) > 0) {
                return true;
            } else {
                ht.insert(n);
            }
        }
        return false;
    }
};

int main() {
    Solution obj;
    auto run = [&](vector<int> nums)->void {
        cout << obj.containsDuplicate(nums) << endl;
    };
    run({1,2,3,1});
    run({1,2,3,4});
    run({1,1,1,3,3,4,3,2,4,2});
    return 0;
}
