/* Say you have an array for which the ith element is the price of a given stock on day i.
 *
 * If you were only permitted to complete at most one transaction
 * (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
 *
 * Example 1:
 * Input: [7, 1, 5, 3, 6, 4]
 * Output: 5
 *
 * max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)
 * Example 2:
 * Input: [7, 6, 4, 3, 1]
 * Output: 0
 *
 * In this case, no transaction is done, i.e. max profit = 0.
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int min_price = -1;
        for (auto & price : prices) {
            if (min_price < 0 || min_price > price) {
                min_price = price;
            }
            int profit = price - min_price;
            if (max_profit < profit) {
                max_profit = profit;
            }
        }
        return max_profit;
    }

    int maxProfitHelper(vector<int> prices) {
        return maxProfit(prices);
    }
};

int main() {
    Solution obj;
    cout << obj.maxProfitHelper({7, 1, 5, 3, 6, 4}) << endl;
    cout << obj.maxProfitHelper({7, 6, 4, 3, 1}) << endl;
    return 0;
}
