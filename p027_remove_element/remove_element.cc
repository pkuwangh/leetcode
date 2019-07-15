/* Given an array and a value,
 * remove all instances of that value in place and return the new length.
 *
 * Do not allocate extra space for another array, you must do this in place with constant memory.
 *
 * The order of elements can be changed. It doesn't matter what you leave beyond the new length.
 *
 * Example:
 * Given input array nums = [3,2,2,3], val = 3
 * Your function should return length = 2, with the first two elements of nums being 2.
 */

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        int cur = 0;
        for (int i = 0; i < size; ++i) {
            if (nums[i] != val) {
                nums[cur] = nums[i];
                ++cur;
            }
        }
        return cur;
    }
};

int main() {
    Solution obj;

    auto run = [&](vector<int> nums, int val) {
        cout << obj.removeElement(nums, val) << ": ";
        for_each(nums.begin(), nums.end(), [](int &n) { cout << n << " "; });
        cout << endl;
    };

    run({3, 2, 2, 3}, 3);
    run({3, 2}, 3);
    run({3, 2, 2, 3}, 3);
    run({3, 2, 2, 3}, 3);
    return 0;
}
