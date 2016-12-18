/* Given numRows, generate the first numRows of Pascal's triangle.
 *
 * For example, given numRows = 5,
 * Return
 * [
 *       [1],
 *      [1,1],
 *     [1,2,1],
 *    [1,3,3,1],
 *   [1,4,6,4,1]
 * ]
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        if (numRows == 0) { return triangle; }
        // push in 1st row
        triangle.push_back(vector<int>(1, 1));
        // calculate from 2nd row
        for (int i = 1; i < numRows; ++i) {
            vector<int> lastRow = triangle[i-1];
            int numCols = i + 1;
            vector<int> row(numCols, 0);
            // set 1st & last element
            row[0] = 1;
            row[numCols-1] = 1;
            // fill the middle elements
            for (int j = 1; j < numCols-1; ++j) {
                row[j] = lastRow[j-1] + lastRow[j];
            }
            triangle.push_back(row);
        }
        return triangle;
    }
};

int main() {
    Solution obj;
    auto triangle = obj.generate(5);
    for (auto & row : triangle) {
        for (auto & n : row) {
            cout << n << " ";
        }
        cout << endl;
    }
    return 0;
}
