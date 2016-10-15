/* Given two binary strings, return their sum (also a binary string).
 *
 * For example,
 * a = "11"
 * b = "1"
 * Return "100".
 */

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
  public:
    string addBinary(string a, string b) {
        // reverse the input strings
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        string sum("");
        int size_a = a.size();
        int size_b = b.size();
        int k = 0;
        int carry = 0;
        while (carry > 0 || k < size_a || k < size_b) {
            if (k < size_a) {
                carry += a[k] - '0';
            }
            if (k < size_b) {
                carry += b[k] - '0';
            }
            sum.push_back('0' + carry % 2);
            carry /= 2;
            ++ k;
        }
        reverse(sum.begin(), sum.end());
        return sum;
    }
};

int main() {
    Solution obj;
    cout << obj.addBinary("11", "1") << endl;
    cout << obj.addBinary("0", "1") << endl;
}
