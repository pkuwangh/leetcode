/* Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
 * Note:
 * You may assume that nums1 has enough space (size that is greater or equal to m + n)
 * to hold additional elements from nums2.
 * The number of elements initialized in nums1 and nums2 are m and n respectively.
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // scan from the end
        int k = m + n - 1;
        while (m > 0 && n > 0) {
            if (nums1[m-1] > nums2[n-1]) {
                nums1[k] = nums1[m-1];
                --m;
            } else {
                nums1[k] = nums2[n-1];
                --n;
            }
            --k;
        }
        while (n > 0) {
            nums1[k] = nums2[n-1];
            --n;
            --k;
        }
    }
};

int main() {
    Solution obj;
    vector<int> num1 = {1, 3, 5, 7, 0, 0, 0, 0, 0};
    vector<int> num2 = {2, 4, 6};
    obj.merge(num1, 4, num2, 3);
    for_each(num1.begin(), num1.end(), [](int &n) { cout << n << " "; });
    cout << endl;
}
