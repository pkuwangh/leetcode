/**
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * Design an algorithm to find the maximum profit.
 * You may complete as many transactions as you like
 * (ie, buy one and sell one share of the stock multiple times) with the following restrictions:
 * You may not engage in multiple transactions at the same time
 * (ie, you must sell the stock before you buy again).
 * After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
 * Example:
 * Input: [1,2,3,0,2]
 * Output: 3 
 * Explanation: transactions = [buy, sell, cooldown, buy, sell]
 */

#include <cassert>
#include <cstdint>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <list>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <functional>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int maxProfit(vector<int>& prices) {
        // dp[i+2] represents the max profit when last sell happens on prices[i]
        if (prices.size() < 2) return 0;
        vector<int> dp(prices.size() + 2, 0);
        // init
        dp[0] = 0;
        dp[1] = 0;
        dp[2] = 0;
        dp[3] = (prices[1] > prices[0]) ? (prices[1] - prices[0]) : 0;
        int max_profit = dp[3];
        // iterate
        for (int i = 2; i < prices.size(); ++i) {
            // derive dp[i+2]
            int min_price = prices[i];
            for (int j = i; j >= 0; --j) {
                min_price = min(prices[j], min_price);
                // day j+2-1 is cool down
                dp[i+2] = max(dp[i+2], dp[j] + prices[i] - min_price);
            }
            max_profit = max(dp[i+2], max_profit);
        }
        return max_profit;
    }
};

int main() {
    Solution obj;
    auto run = [&](vector<int> prices) ->void {
        cout << obj.maxProfit(prices) << endl;
    };
    run({1, 2, 3, 0, 2});
    run({1, 4, 2});
    return 0;
}
