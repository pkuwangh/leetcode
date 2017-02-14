/* Find the contiguous subarray within an array (containing at least one number)
 * which has the largest product.
 * For example, given the array [2,3,-2,4],
 * the contiguous subarray [2,3] has the largest product = 6.
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
  public:
#if 0
    int maxProduct(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return 0;
        int max_product = nums[0];
        vector<vector<int>> product(size, vector<int>(size, 0));
        for (int i = 0; i < size; ++i) {
            product[i][i] = nums[i];
            max_product = max(max_product, nums[i]);
        }
        for (int diff = 1; diff < size; ++diff) {
            for (int i = 0; i+diff < size; ++i) {
                product[i][i+diff] = product[i][i+diff-1] * nums[i+diff];
                max_product = max(max_product, product[i][i+diff]);
            }
        }
        return max_product;
    }
#endif

    int maxProduct(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return 0;
        int ans = nums[0];
        // max_products[i] represents the max product of all subarrays ending at i
        vector<int> max_product(size, nums[0]);
        vector<int> min_product(size, nums[0]);
        for (int i = 1; i < size; ++i) {
            max_product[i] = max(max_product[i-1]*nums[i], min_product[i-1]*nums[i]);
            max_product[i] = max(max_product[i], nums[i]);
            min_product[i] = min(max_product[i-1]*nums[i], min_product[i-1]*nums[i]);
            min_product[i] = min(min_product[i], nums[i]);
            ans = max(ans, max_product[i]);
        }
        return ans;
    }
};

int main() {
    Solution obj;
    auto run = [&obj](vector<int> nums) {
        cout << obj.maxProduct(nums) << endl;
    };
    run({0, 3});
    run({0, -3});
    run({-4, -3});
    run({2, 3, -2, 4});
    run({2, 3, -2, 4, -1});
    return 0;
}
