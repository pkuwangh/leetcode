/* Given a sorted array, remove the duplicates in place such that
 * each element appear only once and return the new length.
 *
 * For example,
 * Given input array nums = [1,1,2],
 *
 * Your function should return length = 2,
 * with the first two elements of nums being 1 and 2 respectively.
 * It doesn't matter what you leave beyond the new length.
 */

/* Follow up for "Remove Duplicates":
 * What if duplicates are allowed at most twice?
 *
 * For example,
 * Given sorted array nums = [1,1,1,2,2,3],
 *
 * Your function should return length = 5,
 * with the first five elements of nums being 1, 1, 2, 2 and 3.
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if (size < 2) return size;
        int end = 0;
        int count = 1;
        for (int i = 1; i < size; ++i) {
            if (nums[end] != nums[i]) {
                count = 1;
                ++ end;
                nums[end] = nums[i];
            } else {
                if (count == 1) {
                    count = 2;
                    ++ end;
                    nums[end] = nums[i];
                }
            }
        }
        return end+1;
    }
};

int main() {
    Solution obj;
    auto run = [&](vector<int> nums) ->void {
        cout << obj.removeDuplicates(nums) << endl;
        for_each(nums.begin(), nums.end(), [](int& n) { cout << n << " "; });
        cout << endl;
    };

    run({});
    run({1, 2, 3});
    run({1, 1, 2});
    run({1, 1, 1, 2, 2, 3});
    run({1, 1, 2, 2, 3, 3, 4});
    return 0;
}
