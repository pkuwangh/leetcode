/* Given an array of integers, every element appears twice except for one.
 * Find that single one.
 *
 * Note:
 * Your algorithm should have a linear runtime complexity.
 * Could you implement it without using extra memory?
 */

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
  public:
#if 0
    // use a hash table, for each element
    // if found in hash table, erase it
    // if not found, insert into hash table
    // the single one will be left
    int singleNumber(vector<int>& nums) {
        unordered_set<int> hash_table;
        for (auto & n : nums) {
            auto iter = hash_table.find(n);
            if (iter == hash_table.end()) {
                hash_table.insert(n);
            } else {
                hash_table.erase(n);
            }
        }
        auto iter = hash_table.begin();
        if (iter != hash_table.end()) {
            return *iter;
        } else {
            return -1;
        }
    }
#endif

    // ultimate method should be using XOR
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for (auto & n : nums) {
            ret = ret ^ n;
        }
        return ret;
    }

    int singleNumberHelper(vector<int> nums) { return singleNumber(nums); }
};

int main() {
    Solution obj;
    cout << obj.singleNumberHelper({0, 1, 0, 2, 2}) << endl;
    return 0;
}
