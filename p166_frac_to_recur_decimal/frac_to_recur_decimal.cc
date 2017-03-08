/* Given two integers representing the numerator and denominator of a fraction,
 * return the fraction in string format.
 * If the fractional part is repeating, enclose the repeating part in parentheses.
 * For example,
 * Given numerator = 1, denominator = 2, return "0.5".
 * Given numerator = 2, denominator = 1, return "2".
 * Given numerator = 2, denominator = 3, return "0.(6)".
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
  public:
    string fractionToDecimal(int numerator, int denominator) {
        bool is_neg = (numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0);
        uint64_t num = abs((int64_t)numerator);
        uint64_t denom = abs((int64_t)denominator);
        uint64_t integer_part = num / denom;
        num -= integer_part * denom;
        vector<uint64_t> fraction_part;
        vector<uint64_t> residual;
        int idx = 0;
        int num_non_repeat = 0;
        while (num > 0) {
            residual.push_back(num);
            fraction_part.push_back(num * 10 / denom);
            num = num * 10 - fraction_part[idx] * denom;
            ++ idx;
            bool repeated = false;
            for (int i = 0; i < idx; ++i) {
                if (num == residual[i]) {
                    num_non_repeat = i;
                    repeated = true;
                    break;
                }
            }
            if (repeated > 0) break;
        }
        string ans;
        if (is_neg) ans.push_back('-');
        ans.append(to_string(integer_part));
        if (idx > 0) ans.push_back('.');
        for (int i = 0; i < num_non_repeat; ++i) ans.push_back('0' + fraction_part[i]);
        if (num > 0) ans.push_back('(');
        for (int i = num_non_repeat; i < idx; ++i) ans.push_back('0' + fraction_part[i]);
        if (num > 0) ans.push_back(')');
        return ans;
    }
};

int main() {
    Solution obj;
    cout << obj.fractionToDecimal(1, 2) << endl;
    cout << obj.fractionToDecimal(2, 1) << endl;
    cout << obj.fractionToDecimal(2, 3) << endl;
    cout << obj.fractionToDecimal(1, 7) << endl;
    cout << obj.fractionToDecimal(4, 90) << endl;
    cout << obj.fractionToDecimal(-2147483648, -1) << endl;
    return 0;
}
