/* Given an integer, convert it to a roman numeral.
 *
 * Input is guaranteed to be within the range from 1 to 3999.
 */

#include <cassert>
#include <string>
#include <iostream>
using namespace std;

class Solution {
  public:
    string intToRoman(int num) {
        static const int num_symbols = 7;
        char symbols[num_symbols+1] = "IVXLCDM";
        int values[num_symbols] = {1, 5, 10, 50, 100, 500, 1000};

        char res[100];
        int k = 0;
        for (int i = num_symbols - 1; i >= 0; i -= 2) {
            int cnt = num / values[i];
            num = num % values[i];
            if (cnt == 9) {
                assert (i + 2 < num_symbols);
                res[k++] = symbols[i];
                res[k++] = symbols[i+2];
                cnt = 0;
            } else if (cnt >= 5) {
                res[k++] = symbols[i+1];
                cnt -= 5;
            } else if (cnt == 4) {
                res[k++] = symbols[i];
                res[k++] = symbols[i+1];
                cnt = 0;
            }

            while (cnt > 0) {
                res[k++] = symbols[i];
                -- cnt;
            }
        }

        return string(res, k);
    }
};

int main() {
    Solution obj;

    for (int i = 1; i <= 20; ++i) {
        cout << obj.intToRoman(i) << ", ";
    }
    cout << endl;

    auto run = [&](int n) { cout << n << " : " << obj.intToRoman(n) << endl; };

    run(39);
    run(40);
    run(41);
    run(49);

    run(1990);

    return 0;
}
