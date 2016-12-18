/* Given an array of integers, every element appears three times except for one.
 * Find that single one.
 * Note:
 * Your algorithm should have a linear runtime complexity.
 * Could you implement it without using extra memory?
 */

#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> num_cnt;
        for (auto & n : nums) {
            auto iter = num_cnt.find(n);
            if (iter == num_cnt.end()) {
                num_cnt[n] = 1;
            } else {
                ++ iter->second;
            }
        }
        auto ans_iter = find_if(num_cnt.begin(), num_cnt.end(),
                [](pair<int, int> e)->bool { return e.second == 1; });
        return ans_iter->first;
    }

    int singleNumberHelper(vector<int> nums) { return singleNumber(nums); }
};

int main() {
    Solution obj;
    cout << obj.singleNumberHelper({1, 2, 2, 1, 4, 2, 1}) << endl;
    return 0;
}
