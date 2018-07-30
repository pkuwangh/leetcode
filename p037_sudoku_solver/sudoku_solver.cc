/* Write a program to solve a Sudoku puzzle by filling the empty cells.
 * 
 * A sudoku solution must satisfy all of the following rules:
 * 
 * Each of the digits 1-9 must occur exactly once in each row.
 * Each of the digits 1-9 must occur exactly once in each column.
 * Each of the the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
 * Empty cells are indicated by the character '.'.
 */

#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

class Solution {
  public:
    void solveSudoku(vector<vector<char>>& board) {
        DFS(board, 0, 0);
    }

    bool DFS(vector<vector<char>>& board, uint32_t row, uint32_t col) {
        // success
        if (row == 8 && col == 9) {
            return true;
        }
        // next row
        if (col == 9) {
            row += 1;
            col = 0;
        }
        if (board[row][col] == '.') {
            bitset<10> candidates;
            findCandidates(board, row, col, candidates);
            for (uint32_t n = 1; n <= 9; ++n) {
                if (candidates[n]) {
                    board[row][col] = '0' + n;
                    // DFS
                    if (DFS(board, row, col+1)) {
                        return true;
                    }
                    // roll back
                    board[row][col] = '.';
                }
            }
            return false;
        } else {
            // DFS
            return DFS(board, row, col+1);
        }
    }

    void findCandidates(vector<vector<char>>& board, uint32_t row, uint32_t col, bitset<10>& candidates) {
        candidates.set();
        for (uint32_t k = 0; k < 9; ++k) {
            // validate row
            if (board[row][k] != '.') candidates.reset(board[row][k] - '0');
            // validate col
            if (board[k][col] != '.') candidates.reset(board[k][col] - '0');
            // validate sub-box
            uint32_t r = 3*(row/3) + k/3;
            uint32_t c = 3*(col/3) + k%3;
            if (board[r][c] != '.') candidates.reset(board[r][c] - '0');
        }
    }
};

int main() {
    vector<char> l1({'5',  '3',  '.',  '.',  '7',  '.',  '.',  '.',  '.'});
    vector<char> l2({'6',  '.',  '.',  '1',  '9',  '5',  '.',  '.',  '.'});
    vector<char> l3({'.',  '9',  '8',  '.',  '.',  '.',  '.',  '6',  '.'});
    vector<char> l4({'8',  '.',  '.',  '.',  '6',  '.',  '.',  '.',  '3'});
    vector<char> l5({'4',  '.',  '.',  '8',  '.',  '3',  '.',  '.',  '1'});
    vector<char> l6({'7',  '.',  '.',  '.',  '2',  '.',  '.',  '.',  '6'});
    vector<char> l7({'.',  '6',  '.',  '.',  '.',  '.',  '2',  '8',  '.'});
    vector<char> l8({'.',  '.',  '.',  '4',  '1',  '9',  '.',  '.',  '5'});
    vector<char> l9({'.',  '.',  '.',  '.',  '8',  '.',  '.',  '7',  '9'});
    vector<vector<char>> board({l1, l2, l3, l4, l5, l6, l7, l8, l9});

    auto display = [](const vector<vector<char>>& board)->void {
        for (auto& line : board) {
            for (auto& n : line) {
                cout << n << " ";
            }
            cout << endl;
        }
    };
    display(board);

    Solution obj;
    obj.solveSudoku(board);

    cout << "---------------------" << endl;
    display(board);
    return 0;
}
