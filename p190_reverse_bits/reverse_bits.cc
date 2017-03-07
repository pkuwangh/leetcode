/* Reverse bits of a given 32 bits unsigned integer.
 * For example, given input 43261596 (represented in binary as 00000010100101000001111010011100),
 * return 964176192 (represented in binary as 00111001011110000010100101000000).
 * Follow up:
 * If this function is called many times, how would you optimize it?
 */

#include <iostream>
using namespace std;

class Solution {
  public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for (int i = 0; i < 32; ++i) {
            ans = (ans << 1) + n % 2;
            n = n >> 1;
        }
        return ans;
    }
};

int main() {
    Solution obj;
    cout << obj.reverseBits(43261596) << endl;
    return 0;
}
