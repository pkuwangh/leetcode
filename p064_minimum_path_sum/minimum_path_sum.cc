/* Given a m x n grid filled with non-negative numbers,
 * find a path from top left to bottom right
 * which minimizes the sum of all numbers along its path.
 * Note: You can only move either down or right at any point in time.
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int minPathSum(vector<vector<int>>& grid) {
        // dynamic programming
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        if (n == 0) return 0;
        // state
        vector<vector<int>> dp(m, vector<int>(n, 0));
        // init
        dp[0][0] = grid[0][0];
        for (int i = 1; i < m; ++i) {
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }
        for (int i = 1; i < n; ++i) {
            dp[0][i] = dp[0][i-1] + grid[0][i];
        }
        // state transition
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
};

int main() {
    Solution obj;
    vector<int> row1({1, 2});
    vector<int> row2({3, 4});
    vector<vector<int>> matrix({row1, row2});
    cout << obj.minPathSum(matrix) << endl;
    return 0;
}
