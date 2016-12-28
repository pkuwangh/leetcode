/* You are given an n x n 2D matrix representing an image.
 * Rotate the image by 90 degrees (clockwise).
 * Follow up:
 * Could you do this in-place?
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        // only need move 1/4 elements
        for (int row = 0; row < size-1; ++row) {
            for (int col = row; col < size-1-row; ++col) {
                int temp = matrix[size-1-col][row]; // 9
                matrix[size-1-col][row] = matrix[size-1-row][size-1-col]; // 9 -> 15
                matrix[size-1-row][size-1-col] = matrix[col][size-1-row]; // 15 -> 8
                matrix[col][size-1-row] = matrix[row][col]; // 8 -> 1
                matrix[row][col] = temp;  // 1 -> 9
            }
        }
    }
};

int main() {
    Solution obj;
    auto run = [&]()->void {
        vector<int> row1({0, 1, 2, 4});
        vector<int> row2({5, 6, 7, 8});
        vector<int> row3({9, 10, 11, 12});
        vector<int> row4({13, 14, 15, 16});
        vector<vector<int>> matrix({row1, row2, row3, row4});
        for_each(matrix.begin(), matrix.end(), [](vector<int>& row)->void {
                for_each(row.begin(), row.end(), [](int &n) { cout << n << " "; });
                cout << endl; });
        obj.rotate(matrix);
        cout << endl;
        for_each(matrix.begin(), matrix.end(), [](vector<int>& row)->void {
                for_each(row.begin(), row.end(), [](int &n) { cout << n << " "; });
                cout << endl; });
    };
    run();
    return 0;
}
