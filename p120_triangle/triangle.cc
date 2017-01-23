/* Given a triangle, find the minimum path sum from top to bottom.
 * Each step you may move to adjacent numbers on the row below.
 * For example, given the following triangle
 * [
 *      [2],
 *     [3,4],
 *    [6,5,7],
 *   [4,1,8,3]
 * ]
 * The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 * Bonus point if you are able to do this using only O(n) extra space,
 * where n is the total number of rows in the triangle.
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() == 0) return 0;
        // dp[j]: min path sum from triangle[i][j] to a leaf
        int n = triangle.size();
        vector<int> sum(n, 0);
        copy(triangle[n-1].begin(), triangle[n-1].end(), sum.begin());
        for (int i = n-2; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                sum[j] = triangle[i][j] + min(sum[j], sum[j+1]);
            }
        }
        return sum[0];
    }

    /*
    int minimumTotal(vector<vector<int>>& triangle) {
        return findMin(triangle, 0, 0);
    }
    int findMin(vector<vector<int>>& triangle, int row, int col) {
        if (row == (int)triangle.size()-1) return triangle.at(row).at(col);
        return triangle[row][col] +
               min(findMin(triangle, row+1, col), findMin(triangle, row+1, col+1));
    }
    */
};

int main() {
    Solution obj;
    vector<int> row1({2});
    vector<int> row2({3, 4});
    vector<int> row3({6, 5, 7});
    vector<int> row4({4, 1, 8, 3});
    vector<vector<int>> triangle({row1, row2, row3, row4});
    cout << obj.minimumTotal(triangle) << endl;
    return 0;
}
