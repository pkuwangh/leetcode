/**
 * Given an integer array nums,
 * find the sum of the elements between indices i and j (i ≤ j), inclusive.
 * Example:
 * Given nums = [-2, 0, 3, -5, 2, -1]
 * sumRange(0, 2) -> 1
 * sumRange(2, 5) -> -1
 * sumRange(0, 5) -> -3
 * Note:
 * You may assume that the array does not change.
 * There are many calls to sumRange function.
 */

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class NumArray {
  public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        sum.resize(n, 0);
        if (n > 0) {
            sum[0] = nums[0];
            for (int i = 1; i < n; ++i) {
                sum[i] = sum[i-1] + nums[i];
            }
        }
    }

    int sumRange(int i, int j) {
        if (i > 0) {
            return sum[j] - sum[i-1];
        } else {
            return sum[j];
        }
    }
  private:
    vector<int> sum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */

int main() {
    vector<int> nums({-2, 0, 3, -5, 2, -1});
    for_each(nums.begin(), nums.end(), [](int& n)->void { cout << n << " "; });
    cout << endl;
    NumArray obj(nums);
    auto run = [&](int i, int j)->void {
        cout << "[" << i << "," << j << "]: ";
        cout << obj.sumRange(i, j) << endl;
    };
    run(0, 2);
    run(2, 5);
    run(0, 5);
    return 0;
}
