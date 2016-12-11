/* Given an array S of n integers, find three integers in S
 * such that the sum is closest to a given number, target.
 * Return the sum of the three integers.
 * You may assume that each input would have exactly one solution.
 *
 * For example, given array S = {-1 2 1 -4}, and target = 1.
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

class Solution {
  public:
    int threeSumClosest(vector<int>& nums, int target) {
        // sort the array
        sort(nums.begin(), nums.end(), [](const int &a, const int &b)->bool { return a < b; });
        // for each element, reduce to 2-sum problem
        int min_diff = -1;
        int ret = target;
        int size = nums.size();
        for (int i = 0; i < size - 2; ++i) {
            // use 2-pointer to scan
            int left = i + 1;
            int right = size - 1;
            while (left != right) {
                int sum = nums[i] + nums[left] + nums[right];
                int diff = abs(sum - target);
                // update min diff
                if (min_diff < 0 || diff < min_diff) {
                    min_diff = diff;
                    ret = sum;
                }
                // update pointer
                if (sum < target) {
                    ++ left;
                } else {
                    -- right;
                }
            }
        }
        return ret;
    }
};

int main()
{
    Solution obj;

    {
        vector<int> vec({-1, 2, 1, -4});
        for_each(vec.begin(), vec.end(), [](int &a)->void { cout << a << " "; });
        cout << endl << obj.threeSumClosest(vec, 1) << endl;
    }

    {
        vector<int> vec({0, 0, 0});
        for_each(vec.begin(), vec.end(), [](int &a)->void { cout << a << " "; });
        cout << endl << obj.threeSumClosest(vec, 1) << endl;
    }

    {
        vector<int> vec({-4,-7,-2,2,5,-2,1,9,3,9,4,9,-9,-3,7,4,1,0,8,5,-7,-7});
        for_each(vec.begin(), vec.end(), [](int &a)->void { cout << a << " "; });
        cout << endl << obj.threeSumClosest(vec, 29) << endl;
    }

    return 0;
}
