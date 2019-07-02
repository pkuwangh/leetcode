/* The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
 * Given an integer n, return the number of distinct solutions to the n-queens puzzle.
 * Example:
 * Input: 4
 * Output: 2
 * Explanation: There are two distinct solutions to the 4-queens puzzle as shown below.
 * [
 *  [".Q..",  // Solution 1
 *   "...Q",
 *   "Q...",
 *   "..Q."],
 * 
 *  ["..Q.",  // Solution 2
 *   "Q...",
 *   "...Q",
 *   ".Q.."]
 *  ]
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int totalNQueens(int n) {
        vector<unsigned> cols(n, 0);   // colume index in each row
        // dfs
        return dfs(cols, 0);
    }

    int dfs(vector<unsigned>& cols, unsigned row) {
        int num_sols = 0;
        // attempting to place a queen on row
        for (unsigned i = 0; i < cols.size(); ++i) {
            if (isValid(cols, row, i)) {
                // found a valid place for the queen
                if (row == cols.size()-1) {
                    // a final solution
                    num_sols += 1;
                } else {
                    // recursive search
                    cols[row] = i;
                    num_sols += dfs(cols, row+1);
                }
            }
        }
        return num_sols;
    }
    
    bool isValid(const vector<unsigned>& cols, unsigned row, unsigned col) {
        for (unsigned i = 0; i < row; ++i) {
            // check colume collision
            if (cols[i] == col) {
                return false;
            }
            // check diagonal
            if ((cols[i] - i) == (col - row) || (cols[i] + i) == (col + row)) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution obj;
    cout << obj.totalNQueens(4) << endl;
    return 0;
}
