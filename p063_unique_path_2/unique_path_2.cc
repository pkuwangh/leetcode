/* Follow up for "Unique Paths":
 * Now consider if some obstacles are added to the grids. How many unique paths would there be?
 *
 * An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 * For example,
 * There is one obstacle in the middle of a 3x3 grid as illustrated below.
 *
 * [
 *   [0,0,0],
 *   [0,1,0],
 *   [0,0,0]
 * ]
 * The total number of unique paths is 2.
 *
 * Note: m and n will be at most 100.
 */

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if (m == 0) { return 0; }
        int n = obstacleGrid[0].size();
        if (n == 0) { return 0; }
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) { return 0; }
        // dynamic programming
        int num[100][100] = {0};
        // initialize
        num[0][0] = 1;
        for (int i = 1; i < m; ++i) {
            if (obstacleGrid[i][0] == 0 && num[i-1][0] > 0) {
                num[i][0] = 1;
            }
        }
        for (int i = 1; i < n; ++i) {
            if (obstacleGrid[0][i] == 0 && num[0][i-1] > 0) {
                num[0][i] = 1;
            }
        }
        // DP
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    num[i][j] = 0;
                } else {
                    num[i][j] = num[i-1][j] + num[i][j-1];
                }
            }
        }
        return num[m-1][n-1];
    }
};

int main() {
    Solution obj;
    vector<int> row1({0, 0, 0});
    vector<int> row2({0, 1, 0});
    vector<int> row3({0, 0, 0});
    vector<vector<int>> matrix({row1, row2, row3});
    cout << obj.uniquePathsWithObstacles(matrix) << endl;
    return 0;
}
