/* Given an integer n, return the number of trailing zeroes in n!.
 * Note: Your solution should be in logarithmic time complexity.
 */

#include <iostream>
using namespace std;

class Solution {
  public:
    int trailingZeroes(int n) {
        int num = 0;
        uint64_t n64 = n;
        uint64_t x = 5;
        while (n64 >= x) {
            num += n64/x;
            x *= 5;
        }
        return num;
    }
};

int main() {
    Solution obj;
    cout << obj.trailingZeroes(26) << endl;
    cout << obj.trailingZeroes(200) << endl;
    cout << obj.trailingZeroes(1808548329) << endl;
}
