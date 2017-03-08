/* Write a function that takes an unsigned integer and
 * returns the number of ’1' bits it has (also known as the Hamming weight).
 * For example, the 32-bit integer ’11' has binary representation
 * 00000000000000000000000000001011, so the function should return 3.
 */

#include <iostream>
using namespace std;

// n and n-1
class Solution {
  public:
    int hammingWeight(uint32_t n) {
        int num = 0;
        while (n > 0) {
            ++ num;
            n = n & (n-1);
        }
        return num;
    }
};

int main() {
    Solution obj;
    cout << obj.hammingWeight(11) << endl;
    return 0;
}
