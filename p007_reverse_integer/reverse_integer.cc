/* Reverse digits of an integer.
 *
 * Example1: x = 123, return 321
 * Example2: x = -123, return -321
 */

#include <climits>
#include <iostream>
using namespace std;

class Solution {
  public:
    int reverse(int x) {
        int res = 0;
        // loop works for both positive and negative naturally
        while (x != 0) {
            int digit = x % 10;
            if (x > 0 && res > (INT_MAX - digit)/10) {
                return 0;
            }
            if (x < 0 && res < (INT_MIN - digit)/10) {
                return 0;
            }

            res = 10 * res + digit;
            x /= 10;
        }
        return res;
    }
};

int main()
{
    Solution obj;

    cout << INT_MAX << endl;
    cout << INT_MIN << endl;

    cout << obj.reverse(123) << endl;
    cout << obj.reverse(-123) << endl;
    cout << obj.reverse(1534236469) << endl;

    return 0;
}
