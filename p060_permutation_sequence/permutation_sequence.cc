/* The set [1,2,3,…,n] contains a total of n! unique permutations.
 * By listing and labeling all of the permutations in order,
 * We get the following sequence (ie, for n = 3):
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 * Given n and k, return the kth permutation sequence.
 * Note: Given n will be between 1 and 9 inclusive.
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
  public:
# if 0
    string getPermutation(int n, int k) {
        // pool of candidate
        vector<int> nums({1, 2, 3, 4, 5, 6, 7, 8, 9});
        // pick from set
        int cnt = 1;
        for (int i = 1; i <= n; ++i) {
            cnt *= i;
        }
        string seq(n, '0');
        --k;
        for (int i = 0; i < n; ++i) {
            cnt = cnt / (n-i);
            int idx = k / cnt;
            // pick idx-th
            int j = 0;
            for (auto & num : nums) {
                if (num > 0) {
                    if (j == idx) {
                        seq[i] = '0' + num;
                        num = -1;
                    }
                    ++j;
                }
            }
            k = k % cnt;
        }
        return seq;
    }
#endif

    string getPermutation(int n, int k) {
        // pool of candidates
        vector<char> nums(n, '1');
        for (int i = 0; i < n; ++i) {
            nums[i] = '1' + i;
        }
        // calculate factorial
        vector<int> factorial(n, 1);
        for (int i = 1; i < n; ++i) {
            factorial[i] = factorial[i-1] * i;
        }
        // get answer
        string seq(n, 0);
        --k;
        for (int i = 0; i < n; ++i) {
            int idx = k / factorial[n-1-i];
            k = k % factorial[n-1-i];
            seq[i] = nums[idx];
            nums.erase(nums.begin() + idx);
        }
        return seq;
    }
};

int main() {
    Solution obj;
    for (int i = 1; i <= 24; ++i) {
        cout << obj.getPermutation(4, i) << endl;
    }
    return 0;
}
