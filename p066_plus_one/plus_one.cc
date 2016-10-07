/* Given a non-negative number represented as an array of digits, plus one to the number.
 *
 * The digits are stored such that the most significant digit is at the head of the list.
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        // overflow case
        bool no_of = any_of(digits.begin(), digits.end(),
                                [](int &n)->bool { return n != 9; });
        if (!no_of) {
            vector<int> res(size+1, 0);
            res[0] = 1;
            return res;
        }
        // normal case
        vector<int> res(size, 0);
        int carry = 1;
        for (int i = size - 1; i >= 0; --i) {
            res[i] = (digits[i] == 9 && carry == 1) ? 0 : (digits[i] + carry);
            carry = (digits[i] == 9 && carry == 1) ? 1 : 0;
        }
        return res;
    }
};

int main() {
    Solution obj;
    auto run = [&obj](vector<int> digits) {
        for_each(digits.begin(), digits.end(), [](int &n)->void { cout << n; });
        auto res = obj.plusOne(digits);
        cout << ": ";
        for_each(res.begin(), res.end(), [](int &n)->void { cout << n; });
        cout << endl;
    };

    run({9, 9, 9});
    run({8, 9, 9});
    run({8, 8, 5, 0, 5, 1, 9, 7});

    return 0;
}
