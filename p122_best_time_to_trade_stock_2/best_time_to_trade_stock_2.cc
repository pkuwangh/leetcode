/* Say you have an array for which the ith element is the price of a given stock on day i.
 *
 * Design an algorithm to find the maximum profit.
 * You may complete as many transactions as you like
 * (ie, buy one and sell one share of the stock multiple times).
 * However, you may not engage in multiple transactions at the same time
 * (ie, you must sell the stock before you buy again).
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        int aggr_profit = 0;
        int hold_price = -1;
        int last_price = prices[0];
        for (unsigned int i = 1; i < prices.size(); ++i) {
            if (prices[i] < last_price) {
                if (hold_price >= 0) {
                    // sell at last point
                    aggr_profit += (last_price - hold_price);
                    hold_price = -1;
                }
            } else {
                // buy at last point
                if (hold_price < 0) {
                    hold_price = last_price;
                }
            }
            last_price = prices[i];
        }
        if (hold_price >= 0) {
            aggr_profit += (last_price - hold_price);
        }
        return aggr_profit;
    }

    int maxProfitHelper(vector<int> prices) {
        return maxProfit(prices);
    }
};

int main() {
    Solution obj;
    cout << obj.maxProfitHelper({2, 1, 2, 0, 1}) << endl;
    return 0;
}
