/* Say you have an array for which the ith element is the price of a given stock on day i.
 * Design an algorithm to find the maximum profit.
 * You may complete at most two transactions.
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2) { return 0; }
        // suppose in 1st transaction, we sell before the ith day
        // prices[0:i]'s max profit w/ one transaction plus
        // prices[i:n-1]'s max profit w/ one transaction
        vector<int> max_left_profits(n, 0);
        // first pass, max profit b/w 0 and i
        int min_price = prices[0];
        for (int i = 1; i < n; ++i) {
            min_price = min(prices[i], min_price);
            max_left_profits[i] = max(max_left_profits[i-1], prices[i] - min_price);
        }
        // second pass, scan from right to left, max profit b/w i and n-1
        int max_profit = max_left_profits[n-1];
        int max_price = prices[n-1];
        int max_right_profit = 0;
        for (int i = n-2; i > 0; --i) {
            max_price = max(prices[i], max_price);
            max_right_profit = max(max_right_profit, max_price - prices[i]);
            // find the max profit w/ 2 transactions
            max_profit = max(max_profit, max_left_profits[i] + max_right_profit);
        }
        return max_profit;
    }

    int maxProfitHelper(vector<int> prices) { return maxProfit(prices); }
};

int main() {
    Solution obj;
    cout << obj.maxProfitHelper({1, 4, 3, 8, 2, 3}) << endl;
    return 0;
}
