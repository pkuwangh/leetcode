/* The gray code is a binary numeral system where two successive values differ in only one bit.
 * Given a non-negative integer n representing the total number of bits in the code,
 * print the sequence of gray code. A gray code sequence must begin with 0.
 *
 * For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
 * 00 - 0
 * 01 - 1
 * 11 - 3
 * 10 - 2
 * Note:
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    vector<int> grayCode(int n) {
        vector<int> codes;
        if (n == 0) {
            codes.push_back(0);
        } else if (n == 1) {
            codes.push_back(0);
            codes.push_back(1);
        } else {
            auto subcodes = grayCode(n-1);
            for (auto it = subcodes.begin(); it != subcodes.end(); ++it) {
                codes.push_back(*it);
            }
            int base = (1 << (n-1));
            for (auto it = subcodes.rbegin(); it != subcodes.rend(); ++it) {
                codes.push_back(*it + base);
            }
        }
        return codes;
    }
};

int main() {
    Solution obj;
    auto run = [&obj](int n) {
        auto ans = obj.grayCode(n);
        for_each(ans.begin(), ans.end(), [](const int &n) { cout << n << " "; });
        cout << endl;
    };
    run(2);
    run(3);
    return 0;
}

