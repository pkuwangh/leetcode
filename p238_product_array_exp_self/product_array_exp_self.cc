/**
 * Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
 * Example:
 * Input:  [1,2,3,4]
 * Output: [24,12,8,6]
 * Note: Please solve it without division and in O(n).
 * Follow up:
 * Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)
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
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> product(size, 1);
        /*
        int product_all = 1;
        int num_zeros = 0;
        for (auto& n : nums) {
            if (n != 0) {
                product_all *= n;
            } else {
                ++ num_zeros;
            }
        }
        for (unsigned i = 0; i < size; ++i) {
            if (num_zeros >= 2) {
                product[i] = 0;
            } else if (num_zeros == 1) {
                if (nums[i] == 0) {
                    product[i] = product_all;
                } else {
                    product[i] = 0;
                }
            } else {
                product[i] = product_all / nums[i];
            }
        }
        */

        // 2 pass, one forward and one backward
        vector<int> product_f(size, 1);
        vector<int> product_b(size, 1);
        for (int i = 1; i < size; ++i) {
            product_f[i] = product_f[i-1] * nums[i-1];
        }
        for (int i = size - 2; i >= 0; --i) {
            product_b[i] = product_b[i+1] * nums[i+1];
        }
        for (int i = 0; i < size; ++i) {
            product[i] = product_f[i] * product_b[i];
        }
        return product;
    }
};

int main() {
    Solution obj;
    auto run = [&](vector<int> nums) ->void {
        auto product = obj.productExceptSelf(nums);
        for (auto& x : product) {
            cout << x << " ";
        }
        cout << endl;
    };
    run({1,2,3,4});
    return 0;
}
