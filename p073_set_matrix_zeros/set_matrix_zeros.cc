/* Given a m x n matrix, if an element is 0, set its entire row and column to 0.
 * Do it in place.
 *
 * Follow up:
 * Did you use extra space?
 * A straight forward solution using O(mn) space is probably a bad idea.
 * A simple improvement uses O(m + n) space, but still not the best solution.
 * Could you devise a constant space solution?
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    void setZeroes(vector<vector<int>>& matrix) {
        size_t num_rows = matrix.size();
        if (num_rows == 0) return;
        size_t num_cols = matrix[0].size();
        if (num_cols == 0) return;
        vector<bool> zero_cols(num_cols, false);
        for (size_t i = 0; i < num_rows; ++i) {
            bool zero_row = false;
            for (size_t j = 0; j < num_cols; ++j) {
                if (matrix[i][j] == 0) {
                    zero_row = true;
                    zero_cols[j] = true;
                }
            }
            if (zero_row) {
                for_each(matrix[i].begin(), matrix[i].end(), [](int& n) { n = 0; });
            }
        }
        for (size_t j = 0; j < num_cols; ++j) {
            if (zero_cols[j]) {
                for (size_t i = 0 ; i < num_rows; ++i) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

int main() {
    Solution obj;
    vector<int> row1({0, 5, 0});
    vector<int> row2({3, 4, 5});
    vector<vector<int>> matrix({row1, row2});
    obj.setZeroes(matrix);
    for (auto &row : matrix) {
        for (auto &n : row) cout << n << " ";
        cout << endl;
    }
    return 0;
}
