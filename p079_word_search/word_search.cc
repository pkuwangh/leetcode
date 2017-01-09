/* Given a 2D board and a word, find if the word exists in the grid.
 * The word can be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring.
 * The same letter cell may not be used more than once.
 *
 * For example,
 * Given board =
 * [
 *   ['A','B','C','E'],
 *   ['S','F','C','S'],
 *   ['A','D','E','E']
 * ]
 * word = "ABCCED", -> returns true,
 * word = "SEE", -> returns true,
 * word = "ABCB", -> returns false.
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
  public:
    bool exist(vector<vector<char> > &board, string word) {
        if(board.empty() || board[0].empty()) return false;
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for(int i=0; i<(int)board.size(); i++) {
            for(int j=0; j<(int)board[i].size(); j++) {
                if(findWord(board, visited, i, j, word, 0)) return true;
            }
        }
        return false;
    }

    bool findWord(const vector<vector<char>> &board, vector<vector<bool>> &visited,
                  int row, int col, string &word, int index) {
        if(index==(int)word.size()) return true;
        if(row<0 || col<0 || row>=(int)board.size() || col>=(int)board[0].size() ||
                visited[row][col] || board[row][col]!=word[index]) {
            return false;
        }
        visited[row][col] = true;
        bool found = false;
        if(findWord(board, visited, row-1, col, word, index+1)) return true;  
        if(findWord(board, visited, row+1, col, word, index+1)) return true;
        if(findWord(board, visited, row, col-1, word, index+1)) return true;
        if(findWord(board, visited, row, col+1, word, index+1)) return true;
#if 0
        found |= findWord(board, visited, row-1, col, word, index+1);  
        found |= findWord(board, visited, row+1, col, word, index+1);
        found |= findWord(board, visited, row, col-1, word, index+1);
        found |= findWord(board, visited, row, col+1, word, index+1);
#endif
        visited[row][col] = false;
        return found;
    }
};

int main() {
    Solution obj;
    vector<char> row1({'A', 'B', 'C', 'E'});
    vector<char> row2({'S', 'F', 'C', 'S'});
    vector<char> row3({'A', 'D', 'E', 'E'});
    vector<vector<char>> board({row1, row2, row3});
    cout << obj.exist(board, "ABCCED") << endl;
    cout << obj.exist(board, "SEE") << endl;
    cout << obj.exist(board, "ABCB") << endl;
    return 0;
}
