/**
 * Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.
 * Example 1:
 * Input: n = 12
 * Output: 3 
 * Explanation: 12 = 4 + 4 + 4.
 *
 * Example 2:
 * Input: n = 13
 * Output: 2
 * Explanation: 13 = 4 + 9.
*/

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int numSquares(int n) {
        // pushing from 1 to n
        vector<int> dp(n+1, 0);
        dp[0] = 0;
        // dp[i] = min(dp[i-k*k]+1)
        // i.e. 1 square + remainder
        for (int i = 1; i <= n; ++i) {
            dp[i] = i;
            for (int k = 1; k*k <= i; ++k) {
                dp[i] = min(dp[i], dp[i-k*k]+1);
            }
        }
        return dp[n];
    }
};

int main() {
    Solution obj;
    auto run = [&](int n)->void {
        cout << n << "->" << obj.numSquares(n) << endl;
    };
    run(12);
    run(13);
    run(20);
    run(8285);
    return 0;
}
