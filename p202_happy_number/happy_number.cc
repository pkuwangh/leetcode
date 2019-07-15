/**
 * Write an algorithm to determine if a number is "happy".
 * A happy number is a number defined by the following process:
 * Starting with any positive integer, replace the number by the sum of the squares of its digits,
 * and repeat the process until the number equals 1 (where it will stay),
 * or it loops endlessly in a cycle which does not include 1.
 * Those numbers for which this process ends in 1 are happy numbers.
 * Example: 
 * Input: 19
 * Output: true
 * Explanation: 
 * 1^2 + 9^2 = 82
 * 8^2 + 2^2 = 68
 * 6^2 + 8^2 = 100
 * 1^2 + 0^2 + 0^2 = 1
 */

#include <unordered_set>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
  public:
    bool isHappy(int n) {
        unordered_set<int> numbers;
        while (n != 1) {
            if (numbers.count(n) > 0) {
                break;
            }
            numbers.insert(n);
            int sum = 0;
            while (n > 0) {
                int x = n % 10;
                n = n / 10;
                sum += x*x;
            }
            n = sum;
        }
        return (n == 1);
    }
};

int main() {
    Solution obj;
    cout << obj.isHappy(19) << endl;
    cout << obj.isHappy(2) << endl;
    return 0;
}
