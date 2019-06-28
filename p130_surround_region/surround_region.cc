/* Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
 * A region is captured by flipping all 'O's into 'X's in that surrounded region.
 * Example:
 * X X X X
 * X O O X
 * X X O X
 * X O X X
 * After running your function, the board should be:
 * X X X X
 * X X X X
 * X X X X
 * X O X X
 * Explanation:
 * Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'.
 * Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'.
 * Two cells are connected if they are adjacent cells connected horizontally or vertically.
 */

#include <vector>
#include <utility>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
  public:
    void solve(vector<vector<char>>& board) {
        queue<pair<int, int>> to_visit;
        const int num_rows = board.size();
        if (num_rows == 0) return;
        const int num_cols = board[0].size();
        // inited node to visit
        for (int i = 0; i < num_rows; ++i) {
            if (board[i][0] == 'O') {
                to_visit.push(make_pair(i, 0));
            }
            if (board[i][num_cols-1] == 'O') {
                to_visit.push(make_pair(i, num_cols-1));
            }
        }
        for (int i = 0; i < num_cols; ++i) {
            if (board[0][i] == 'O') {
                to_visit.push(make_pair(0, i));
            }
            if (board[num_rows-1][i] == 'O') {
                to_visit.push(make_pair(num_rows-1, i));
            }
        }
        // bfs
        while (!to_visit.empty()) {
            pair<int, int> node = to_visit.front();
            to_visit.pop();
            board[node.first][node.second] = 'Y';
            if (node.first > 0) {
                if (board[node.first-1][node.second] == 'O') {
                    to_visit.push(make_pair(node.first-1, node.second));
                }
            }
            if (node.second > 0) {
                if (board[node.first][node.second-1] == 'O') {
                    to_visit.push(make_pair(node.first, node.second-1));
                }
            }
            if (node.first < num_rows-1) {
                if (board[node.first+1][node.second] == 'O') {
                    to_visit.push(make_pair(node.first+1, node.second));
                }
            }
            if (node.second < num_cols-1) {
                if (board[node.first][node.second+1] == 'O') {
                    to_visit.push(make_pair(node.first, node.second+1));
                }
            }
        }
        // change the pattern
        for (int i =0; i < num_rows; ++i) {
            for (int j = 0; j < num_cols; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                if (board[i][j] == 'Y') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};

int main() {
    Solution obj;
    auto run = [&](vector<vector<char>> board) {
        for (unsigned i = 0; i < board.size(); ++i) {
            for (unsigned j = 0; j < board[i].size(); ++j) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        obj.solve(board);
        for (unsigned i = 0; i < board.size(); ++i) {
            for (unsigned j = 0; j < board[i].size(); ++j) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    };
    run({{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}});
    run({{'X','O','X','X'},{'O','X','O','X'},{'X','O','X','O'},{'O','X','O','X'},{'X','O','X','O'},{'O','X','O','X'}});
    return 0;
}
