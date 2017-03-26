/* Find the kth largest element in an unsorted array.
 * Note that it is the kth largest element in the sorted order, not the kth distinct element.
 * For example,
 * Given [3,2,1,5,6,4] and k = 2, return 5.
 */

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), [](const int& e1, const int&e2)->bool {return e2<e1;});
        return nums[k-1];
    }
};

int main() {
    Solution obj;
    auto run = [&obj](vector<int> nums, int k) {
        cout << obj.findKthLargest(nums, k) << endl;
    };
    run(vector<int>({3,2,1,5,6,4}), 2);
    return 0;
}
