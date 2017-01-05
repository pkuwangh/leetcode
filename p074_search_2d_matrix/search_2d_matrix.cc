/* Write an efficient algorithm that searches for a value in an m x n matrix.
 * This matrix has the following properties:
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the previous row.
 * For example,
 * Consider the following matrix:
 * [
 *   [1,   3,  5,  7],
 *   [10, 11, 16, 20],
 *   [23, 30, 34, 50]
 * ]
 * Given target = 3, return true.
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // binary search
        int num_rows = matrix.size();
        if (num_rows == 0) return false;
        int num_cols = matrix[0].size();
        if (num_cols == 0) return false;

        int low = 0, high = num_rows-1;
        while (low <= high) {
            cout << "low=" << low << ", high=" << high << endl;
            int mid = (low+high)/2;
            if (matrix[mid][0] == target) return true;
            if (matrix[mid][0] < target) {
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        // search in row[high]
        int row = high;
        if (row < 0) return false;
        low = 0, high = num_cols-1;
        while (low <= high) {
            int mid = (low+high)/2;
            if (matrix[row][mid] == target) return true;
            if (matrix[row][mid] < target) {
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        return false;
    }
};

int main() {
    Solution obj;
    /*
    vector<int> row1({1, 3, 5, 7});
    vector<int> row2({10, 11, 16, 20});
    vector<int> row3({23, 30, 34, 50});
    vector<vector<int>> matrix({row1, row2, row3});
    */
    vector<int> row1({1});
    vector<int> row2({3});
    vector<vector<int>> matrix({row1, row2});
    cout << obj.searchMatrix(matrix, 0) << endl;
    return 0;
}
