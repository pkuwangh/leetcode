/* A robot is located at the top-left corner of a m x n grid.
 * The robot can only move either down or right at any point in time.
 * The robot is trying to reach the bottom-right corner of the grid.
 *
 * How many possible unique paths are there?
 */

#include <iostream>
using namespace std;

class Solution {
  public:
    // Time Limit Exceeded
#if 0
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1) return 1;
        int num = 0;
        if (m > 1) num += uniquePaths(m-1, n);
        if (n > 1) num += uniquePaths(m, n-1);
        return num;
    }
#endif

    // DP: num[m][n] = num[m-1][n] + num[m][n-1]
    int uniquePaths(int m, int n) {
        int num[100][100];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                num[i][j] = 0;
            }
        }
        // initialize
        for (int i = 0; i < m; ++i) {
            num[i][0] = 1;
        }
        for (int i = 0; i < n; ++i) {
            num[0][i] = 1;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                num[i][j] = num[i-1][j] + num[i][j-1];
            }
        }
        return num[m-1][n-1];
    }
};

int main() {
    Solution obj;
    cout << obj.uniquePaths(2, 2) << endl;
    return 0;
}
