/* Given an array S of n integers, are there elements a, b, c in S
 * such that a + b + c = 0? Find all unique triplets in the array
 * which gives the sum of zero.
 *
 * Note: The solution set must not contain duplicate triplets.
 *
 * For example, given array S = [-1, 0, 1, 2, -1, -4],
 *
 * A solution set is:
 * [
 *   [-1, 0, 1],
 *     [-1, -1, 2]
 *     ]
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define DEBUG

class Solution {
  public:
    vector<vector<int>> threeSum(vector<int>& nums) {
#ifdef DEBUG
        auto print_vector = [](vector<int>& v)->void {
            for_each(v.begin(), v.end(), [](int &n)->void { cout << n << "  "; });
            cout << endl;
        };

        cout << "input vector: ";
        print_vector(nums);
#endif
        // sort the vector to help avoid duplicates
        sort(nums.begin(), nums.end(), [](const int &a, const int &b) ->bool { return a < b; });
        // for each n1, use 2-pointer method to find two-sum answer
        int size = nums.size();
        vector<vector<int>> res;
        for (int i = 0; i < size; ++i) {
            // avoid duplicates in n1
            if (i > 0 && nums[i-1] == nums[i]) {
                continue;
            }
            // find 2 nums (n2 & n3); their sum should be -n1
            int target = -nums[i];
            int left = i + 1;
            int right = size - 1;
            while (left < right) {
                int sum = nums[left] + nums[right];
                if (sum == target) {
                    // find an answer
                    vector<int> ans = {nums[i], nums[left], nums[right]};
                    res.push_back(ans);
#ifdef DEBUG
                    print_vector(ans);
#endif
                    ++left;
                    --right;
                    // avoid duplicates
                    while (left < size && nums[left] == nums[left-1]) ++left;
                    while (right > 0 && nums[right] == nums[right+1]) --right;
                } else if (sum < target) {
                    ++left;
                } else {
                    --right;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution obj;

    vector<int> test1 = {-1, 0, 1, 2, -1, -4};
    obj.threeSum(test1);

    vector<int> test2 = {0, 0, 0};
    obj.threeSum(test2);

    vector<int> test3 = {1, -1, -1, 0};
    obj.threeSum(test3);

    return 0;
}
