/* Implement pow(x, n)
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    double myPow(double x, int n) {
        long long int next = n;
        if (n > 0) {
            return myPowPositive(x, next);
        } else if (n < 0) {
            return 1 / myPowPositive(x, -next);
        } else {
            return 1;
        }
    }

    double myPowPositive(double x, long long int n) {
        // only calculae x^1, x^2, x^4, x^8, x^16 ... x^max_shift
        static const long long int one = 1;
        int max_shift = 1;
        while ((one << max_shift) <= n) ++max_shift;
        // build a map
        vector<double> table(max_shift, 1);
        table[0] = x;
        for (int i = 1; i < max_shift; ++i) {
            table[i] = table[i-1] * table[i-1];
        }
        // calculate
        double ans = 1;
        int idx = max_shift;
        while (n > 0) {
            long long nsub = (one << idx);
            if (nsub <= n) {
                n -= nsub;
                ans *= table[idx];
            } else {
                -- idx;
            }
        }
        return ans;
    }
};

int main() {
    Solution obj;
    cout << obj.myPow(3, 4) << endl;
    cout << obj.myPow(34.00515, -3) << endl;
    cout << obj.myPow(0.00001, 2147483647) << endl;
    cout << obj.myPow(1.0000, -2147483648) << endl;
    return 0;
}
