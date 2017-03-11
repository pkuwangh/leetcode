/* Given an unsorted array,
 * find the maximum difference between the successive elements in its sorted form.
 * Try to solve it in linear time/space.
 * Return 0 if the array contains less than 2 elements.
 * You may assume all elements in the array are non-negative integers and
 * fit in the 32-bit signed integer range.
 */

#include <vector>
#include <iostream>
using namespace std;

class Solution {
  public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        // find max & min num
        int64_t maxNum = nums[0];
        int64_t minNum = nums[0];
        for (int& x : nums) {
            maxNum = max(maxNum, (int64_t)x);
            minNum = min(minNum, (int64_t)x);
        }
        // size of each bucket
        int size = (maxNum - minNum) / nums.size() + 1;
        int num_buckets = (maxNum - minNum) / size + 1;
        vector<vector<int>> buckets(num_buckets, vector<int>(3, 0));
        for (int& x : nums) {
            int i = (x - minNum) / size;
            if (buckets[i][0] == 0) {
                buckets[i][0] = 1;
                buckets[i][1] = x;
                buckets[i][2] = x;
            } else {
                buckets[i][0] = 1;                      // valid
                buckets[i][1] = min(buckets[i][1], x);  // min
                buckets[i][2] = max(buckets[i][2], x);  // max
            }
        }
        // calculate gap
        int gap = 0;
        int prev = 0;
        for (int i = 1; i < num_buckets; ++i) {
            if (buckets[i][0] == 0) continue; // empty bucket
            gap = max(gap, buckets[i][1] - buckets[prev][2]);
            prev = i;
        }
        return gap;
    }
};

int main() {
    Solution obj;
    auto run = [&obj](vector<int> nums) {
        cout << obj.maximumGap(nums) << endl;
    };
    run({1,2,3,5,6});
    return 0;
}
