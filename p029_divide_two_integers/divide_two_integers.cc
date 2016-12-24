/* Divide two integers without using multiplication, division and mod operator.
 * If it is overflow, return MAX_INT.
 */

#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int divide(int dividend, int divisor) {
        if (divisor == 0) return INT_MAX;
        if (dividend == INT_MIN && divisor == -1) return INT_MAX; // overflow
        bool neg = (dividend > 0) ^ (divisor > 0);
        long long dvd = dividend;
        dvd = abs(dvd);
        long long dvs = divisor;
        dvs = abs(dvs);
        // time limit exceeded if brute force
        int shift = 0;
        while ( (dvs << (shift+1)) <= dvd ) {
            ++ shift;
        }

        int ans = 0;
        while (dvd >= dvs) {
            if (dvd >= (dvs << shift)) {
                ans += (1 << shift);
                dvd -= (dvs << shift);
            }
            -- shift;
        }
        return (neg ? -ans : ans);
    }
};

int main() {
    Solution obj;
    cout << obj.divide(25, 7) << endl;
    cout << obj.divide(INT_MIN, 1) << endl;
    cout << INT_MAX << endl;
    cout << INT_MIN << endl;
    return 0;
}
