/* Say you have an array for which the ith element is the price of a given stock on day i.
 * Design an algorithm to find the maximum profit. You may complete at most k transactions.
 * Note:
 * You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 * Example 1:
 * Input: [2,4,1], k = 2
 * Output: 2
 * Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
 * Example 2:
 * Input: [3,2,6,5,0,3], k = 2
 * Output: 7
 * Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4.
 *              Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int maxProfit(int k, vector<int>& prices) {
        // 2-D dynamic programming
        // why? one dimension along the price vector; another dimension along k transactions
        int n = prices.size();
        if (k == 0 || n == 0) return 0;
        if (k >= n/2) {
            // grab every opportunity
            int profit = 0;
            for (int i = 1; i < n; ++i) {
                if (prices[i] > prices[i-1]) {
                    profit += (prices[i] - prices[i-1]);
                }
            }
            return profit;
        }
        // dp[i][j] represent max profit w/ j-th transactions on day i
        vector<vector<int>> dp(n, vector<int>(k+1, 0));
        // push to right bottom corner
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j <= k; ++j) {
                // option 1: no operation on day i
                dp[i][j] = dp[i-1][j];
                // option 2: add one more transaction finished on day i
                // scan through to determine when to finish transaction j-1
                for (int x = 0; x < i; ++x) {
                    dp[i][j] = max(dp[x][j-1] + prices[i] - prices[x], dp[i][j]);
                }
            }
        }
        // find max profit w/ k transactions
        return dp[n-1][k];
    }
};

int main() {
    Solution obj;
    auto run = [&](int k, vector<int> prices) {
        for_each(prices.begin(), prices.end(), [](int& x)->void { cout << x << " "; });
        cout << endl;
        cout << obj.maxProfit(k, prices) << endl;
    };
    run(2, {1, 2, 4});
    run(2, {2, 4, 1});
    run(2, {3, 2, 6, 5, 0, 3});
    run(2, {});
}
