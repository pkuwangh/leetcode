/* Given two numbers represented as strings, return multiplication of the numbers as a string.
 *
 * Note:
 * The numbers can be arbitrarily large and are non-negative.
 * Converting the input string to integer is NOT allowed.
 * You should NOT use internal library such as BigInteger.
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
  public:
    string multiply(string num1, string num2) {
        int size1 = num1.size();
        int size2 = num2.size();
        int size = size1 + size2;
        vector<int> product(size, 0);
        for (int i = 0; i < size1; ++i) {
            int n1 = (int)(num1[size1-1-i] - '0');
            int carry = 0;
            for (int j = 0; j < size2; ++j) {
                int n2 = (int)(num2[size2-1-j] - '0');
                int mac = n1 * n2 + carry + product[j+i];
                carry = mac/10;
                product[j+i] = mac % 10;
            }
            // handle carry
            while (carry > 0) {
                int sum = carry + product[size2+i];
                carry = sum/10;
                product[size2+i] = sum % 10;
            }
        }
        // remove leading 0s
        while (size > 0 && product[size-1] == 0) {
            --size;
        }
        if (size == 0) return string(1, '0');
        string ans(size, 0);
        for (int i = 0; i < size; ++i) {
            ans[i] = (char)('0' + product[size-1-i]);
        }
        return ans;
    }
};

int main() {
    Solution obj;
    auto run = [&](string num1, string num2)->void {
        auto ans = obj.multiply(num1, num2);
        cout << ans << endl;
    };
    run("25", "1");
    run("25", "11");
    run("25", "16");
    run("0", "16");
    return 0;
}
