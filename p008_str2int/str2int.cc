/* Implement atoi to convert a string to an integer.
 *
 * Hint: Carefully consider all possible input cases.
 *
 * Notes: It is intended for this problem to be specified vaguely (ie, no given input specs).
 * You are responsible to gather all the input requirements up front. 
 *
 * Requirements for atoi: 
 * The function first discards as many whitespace characters as necessary
 * until the first non-whitespace character is found.
 * Then, starting from this character, takes an optional initial plus or minus sign
 * followed by as many numerical digits as possible, and interprets them as a numerical value.

 * The string can contain additional characters after those that form the integral number,
 * which are ignored and have no effect on the behavior of this function.

 * If the first sequence of non-whitespace characters in str is not a valid integral number,
 * or if no such sequence exists because either str is empty or it contains only whitespace
 * characters, no conversion is performed.

 * If no valid conversion could be performed, a zero value is returned.
 * If the correct value is out of the range of representable values,
 * INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.

*/

#include <climits>
#include <string>
#include <iostream>
using namespace std;

class Solution {
  public:
    int myAtoi(string str) {
        int num = 0;
        bool sign = true;   // true - postive, false - negative
        bool start = false;

        for (size_t i = 0; i < str.length(); ++i) {
            int c = str[i] - '0';
            if (c < 0 || c > 9) {
                if (start) {
                    // the number is over
                    break;
                } else {
                    switch (str[i]) {
                        case '+': sign = true; start = true; break;
                        case '-': sign = false; start = true; break;
                        case ' ': break;
                        default: return 0; break;
                    }
                }
            } else {
                start = true;
                // check for overflow
                if (sign) {
                    if (num > (INT_MAX - c)/10) {
                        return INT_MAX;
                    }
                } else {
                    if (-num < (INT_MIN + c)/10) {
                        return INT_MIN;
                    }
                }
                // safely add the digit, no overflow
                num = 10 * num + c;
            }
        }
        if (sign == false) {
            num = -num;
        }
        return num;
    }
};

int main()
{
    Solution obj;

    cout << obj.myAtoi("0") << endl;
    cout << obj.myAtoi("-10") << endl;
    cout << obj.myAtoi("1239") << endl;
    cout << obj.myAtoi("  -0012a42") << endl;
    cout << obj.myAtoi("2147483648") << endl;
    cout << obj.myAtoi(" b11228552307") << endl;

    return 0;
}

