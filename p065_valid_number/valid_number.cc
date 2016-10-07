/* Validate if a given string is numeric.
 *
 * Some examples:
 * "0" => true
 * " 0.1 " => true
 * "abc" => false
 * "1 a" => false
 * "2e10" => true
 *
 * Note: It is intended for the problem statement to be ambiguous.
 * You should gather all requirements up front before implementing one.
 */

#include <iostream>
#include <string>
using namespace std;

class Solution {
  public:
    bool isNumber(string s) {
        bool start = false;
        bool end = false;
        bool sign = false;
        bool exp = false;
        bool exp_valid = true;
        bool exp_sign = false;
        bool dot = false;
        for (int i = 0; i < (int)s.length(); ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                if (end) {
                    return false;
                }
                if (exp) {
                    exp_valid = true;
                }
                start = true;
            } else if (s[i] == 'e') {
                if (!start || end || exp) {
                    return false;
                }
                exp = true;
                exp_valid = false;
            } else if (s[i] == '.') {
                if (end || dot || exp) {
                    return false;
                }
                dot = true;
            } else if (s[i] == '-' || s[i] == '+') {
                if (!exp_valid) {
                    if (exp_sign) {
                        return false;
                    }
                    exp_sign = true;
                } else if (start || end || dot || sign) {
                    return false;
                }
                sign = true;
            } else if (s[i] == ' ') {
                if (start || dot || sign) {
                    end = true;
                }
            } else {
                return false;
            }
        }
        return start && exp_valid;
    }
};

int main() {
    Solution obj;
    auto run = [&obj](string s) {
        cout << s << ":\t" << (obj.isNumber(s) ? "true" : "false") << endl;
    };

    run("0");
    run(" 0.1");
    run("abc");
    run("1 a");
    run("2e10");

    run(".");
    run("1 ");
    run("2e");
    run("-1.");
    run("+ 2");
    run("46.e3");
    run(" 005047e+10");

    return 0;
}
