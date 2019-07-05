/* Given a 2d grid map of '1's (land) and '0's (water), count the number of islands.
 * An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
 * You may assume all four edges of the grid are all surrounded by water.
 * Example 1:
 * Input:
 * 11110
 * 11010
 * 11000
 * 00000
 * Output: 1
 * 
 * Example 2:
 * Input:
 * 11000
 * 11000
 * 00100
 * 00011
 * Output: 3
 */

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
  public:
    int numIslands(vector<vector<char>>& grid) {
        int num_islands = 0;
        for (unsigned i = 0; i < grid.size(); ++i) {
            for (unsigned j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == '1') {
                    ++ num_islands;
                    dfs(grid, i, j);
                }
            }
        }
        return num_islands;
    }
    void dfs(vector<vector<char>>& grid, unsigned row, unsigned col) {
        grid[row][col] = 'x';
        if (row > 0 && grid[row-1][col] == '1') {
            dfs(grid, row-1, col);
        }
        if (col > 0 && grid[row][col-1] == '1') {
            dfs(grid, row, col-1);
        }
        if (row < grid.size() - 1 && grid[row+1][col] == '1') {
            dfs(grid, row+1, col);
        }
        if (col < grid[0].size() - 1 && grid[row][col+1] == '1') {
            dfs(grid, row, col+1);
        }
    }
};

int main() {
    Solution obj;
    auto display = [](const vector<vector<char>>& grid)->void {
        for (unsigned i = 0; i < grid.size(); ++i) {
            for (unsigned j = 0; j < grid[i].size(); ++j) {
                cout << grid[i][j];
            }
            cout << endl;
        }
    };
    auto run = [&](vector<vector<char>> grid)->void {
        display(grid);
        cout << obj.numIslands(grid) << endl;
        display(grid);
        cout << endl;
    };
    run({{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'}});
    run({{'1','1','0','0','0'},{'1','1','0','0','0'},{'0','0','1','0','0'},{'0','0','0','1','1'}});
    return 0;
}
