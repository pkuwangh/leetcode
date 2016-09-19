/* Determine whether an integer is a palindrome. Do this without extra space.
 */

#include <iostream>
#include <cmath>

using namespace std;

class Solution {
  public:
    bool isPalindrome(int x) {
        if (x < 0) return false;  // negative number cannot be palindrome
        // get the number of digits
        int num_digits = 0;
        int temp = x;
        while (temp > 0) {
            ++ num_digits;
            temp /= 10;
        }
        // compare from both ends
        for (int i = 0; i < num_digits / 2; ++i) {
            int lsb = (x / (int)pow(10, i)) % 10;
            int msb = (x / (int)pow(10, num_digits - i -1)) % 10;
            if (lsb != msb) return false;
        }
        return true;
    }
};

int main() {
    Solution obj;

    cout << "12321: " << obj.isPalindrome(12321) << endl;
    cout << "12371: " << obj.isPalindrome(12371) << endl;
    cout << "123371: " << obj.isPalindrome(123321) << endl;
    cout << "123471: " << obj.isPalindrome(123421) << endl;

    return 0;
}

