/* Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
 * The Sudoku board could be partially filled,
 * where empty cells are filled with the character '.'.
 * Note:
 * A valid Sudoku board (partially filled) is not necessarily solvable.
 * Only the filled cells need to be validated.
 */

#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

class Solution {
  public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<bitset<9>> row_checker(9, 0);
        vector<bitset<9>> col_checker(9, 0);
        vector<bitset<9>> box_checker(9, 0);
        // scan all numbers once
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                int row = i;
                int col = j;
                int box = (i/3) * 3 + (j/3);

                if (board[i][j] == '.') {
                    continue;
                } else {
                    int n = board[i][j] - '1';
                    // row
                    if (row_checker[row].test(n)) {
                        return false;
                    } else {
                        row_checker[row].set(n);
                    }
                    // col
                    if (col_checker[col].test(n)) {
                        return false;
                    } else {
                        col_checker[col].set(n);
                    }
                    // sub-box
                    if (box_checker[box].test(n)) {
                        return false;
                    } else {
                        box_checker[box].set(n);
                    }
                }
            }
        }
        return true;
    }
};

int main() {
    Solution obj;
    vector<char> row(9, '.');
    vector<vector<char>> board(9, row);
    cout << obj.isValidSudoku(board) << endl;
    return 0;
}
