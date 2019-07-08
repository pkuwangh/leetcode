/**
 * Given a 2D matrix matrix, find the sum of the elements inside the rectangle
 * defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
 * Range Sum Query 2D
 * Example:
 * Given matrix = [
 *   [3, 0, 1, 4, 2],
 *   [5, 6, 3, 2, 1],
 *   [1, 2, 0, 1, 5],
 *   [4, 1, 0, 1, 7],
 *   [1, 0, 3, 0, 5]
 * ]
 * sumRegion(2, 1, 4, 3) -> 8
 * sumRegion(1, 1, 2, 2) -> 11
 * sumRegion(1, 2, 2, 4) -> 12
 * Note:
 * You may assume that the matrix does not change.
 * There are many calls to sumRegion function.
 * You may assume that row1 ≤ row2 and col1 ≤ col2.
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class NumMatrix {
  public:
    NumMatrix(vector<vector<int>>& matrix) {
        int num_rows = matrix.size();
        if (num_rows > 0) {
            int num_cols = matrix[0].size();
            if (num_cols > 0) {
                sum.resize(num_rows, vector<int>(num_cols, 0));
                sum[0][0] = matrix[0][0];
                for (int i = 1; i < num_rows; ++i) {
                    sum[i][0] = sum[i-1][0] + matrix[i][0];
                }
                for (int j = 1; j < num_cols; ++j) {
                    sum[0][j] = sum[0][j-1] + matrix[0][j];
                }
                for (int i = 1; i < num_rows; ++i) {
                    for (int j = 1; j < num_cols; ++j) {
                        sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + matrix[i][j];
                    }
                }
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        const int sum_b_r = sum[row2][col2];
        const int sum_u_r = row1 > 0 ? sum[row1-1][col2] : 0;
        const int sum_b_l = col1 > 0 ? sum[row2][col1-1] : 0;
        const int sum_u_l = (row1 > 0 && col1 >0) ? sum[row1-1][col1-1] : 0;
        return (sum_b_r + sum_u_l - sum_u_r - sum_b_l);
    }
  private:
    vector<vector<int>> sum;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

int main() {
    vector<vector<int>> matrix({
            {3, 0, 1, 4, 2},
            {5, 6, 3, 2, 1},
            {1, 2, 0, 1, 5},
            {4, 1, 0, 1, 7},
            {1, 0, 3, 0, 5}});
    for (auto& row : matrix) {
        for (auto& n : row) {
            cout << n << " ";
        }
        cout << endl;
    }
    NumMatrix obj(matrix);
    auto run = [&](int row1, int col1, int row2, int col2)->void {
        cout << "(" << row1 << "," << col1 << ") - (" << row2 << "," << col2 << "):";
        cout << obj.sumRegion(row1, col1, row2, col2) << endl;
    };
    run(2, 1, 4, 3);
    run(1, 1, 2, 2);
    run(1, 2, 2, 4);
    return 0;
}
