/* You are climbing a stair case. It takes n steps to reach to the top.
 * Each time you can either climb 1 or 2 steps.
 * In how many distinct ways can you climb to the top?
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int climbStairs(int n) {
        vector<int> num(n+3, 0);
        num[0] = 0;
        num[1] = 1;
        num[2] = 2;
        for (int i = 3; i <= n; ++i) {
            num[i] = num[i-2] + num[i-1];
        }
        return num[n];
    }
};

int main() {
    Solution obj;
    cout << obj.climbStairs(3) << endl; // 3
    cout << obj.climbStairs(44) << endl;
    return 0;
}
