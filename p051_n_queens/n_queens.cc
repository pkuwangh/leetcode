/* The n-queens puzzle is the problem of placing n queens on an n×n chessboard
 * such that no two queens attack each other.
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 *
 * Each solution contains a distinct board configuration of the n-queens' placement,
 * where 'Q' and '.' both indicate a queen and an empty space respectively.
 *
 * For example,
 * There exist two distinct solutions to the 4-queens puzzle:
 *
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
 *
 */

#include <string>
#include <iostream>
#include <vector>
using namespace std;

#define DEBUG

class Solution {
  public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> all_sols;
        vector<string> sol(n, string(n, '.'));
        vector<int> sol_cols(n, 0);
        placeQueen(all_sols, sol, sol_cols, n, 0);
        return all_sols;
    }

    void placeQueen(vector<vector<string>> &all_sols, vector<string> &sol,
                    vector<int> & sol_cols, int n, int row)
    {
        if (row == n) {
            // all the queens have been placed
#ifdef DEBUG
            print_sol(sol);
#endif
            all_sols.push_back(sol);
            return;
        }
        // find a valid col for queen
        for (int i = 0; i < n; ++i) {
            if (isValidPos(sol_cols, row, i)) {
                // found a valid col on this row
                sol_cols[row] = i;
                sol[row][i] = 'Q';
                // DFS
                placeQueen(all_sols, sol, sol_cols, n, row+1);
                // roll back
                sol_cols[row] = 0;
                sol[row][i] = '.';
            }
        }
        return;
    }

    bool isValidPos(const vector<int> & sol_cols, int row, int col) {
        for (int i = 0; i < row; ++i) {
            // check for same-column conflict
            if (sol_cols[i] == col) {
                return false;
            }
            // check for diagonal-line conflict
            if ( (row - i) == (sol_cols[i] - col) ||
                 (row - i) == (col - sol_cols[i]) ) {
                return false;
            }
        }
        return true;
    }

    void print_sol(const vector<string> &sol) {
        for (auto & str : sol) {
            cout << str << endl;
        }
        cout << endl;
    }
};

int main() {
    Solution obj;

    obj.solveNQueens(4);
//    obj.solveNQueens(8);

    return 0;
}
