/*
 * Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
 * Example:
 * Input: 
 * 1 0 1 0 0
 * 1 0 1 1 1
 * 1 1 1 1 1
 * 1 0 0 1 0
 * 
 * Output: 4
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) return 0;
        vector<vector<int>> lens(matrix.size(), vector<int>(matrix[0].size(), 0));
        int max_len = 0;
        // initialize first row & col
        const int max_rows = matrix.size();
        const int max_cols = matrix[0].size();
        for (int i = 0; i < max_rows; ++i) {
            if (matrix[i][0] == '1') {
                lens[i][0] = 1;
                max_len = 1;
            }
        }
        for (int i = 0; i < max_cols; ++i) {
            if (matrix[0][i] == '1') {
                lens[0][i] = 1;
                max_len = 1;
            }
        }
        // dynamic programming begins
        for (int i = 1; i < max_rows; ++i) {
            for (int j = 1; j < max_cols; ++j) {
                if (matrix[i][j] == '1') {
                    lens[i][j] = 1;
                    if (lens[i-1][j-1] > 0) {
                        // try to extend
                        for (int k = 1; k <= lens[i-1][j-1]; ++k) {
                            if (matrix[i-k][j] == '0' || matrix[i][j-k] == '0') {
                                break;
                            }
                            lens[i][j] += 1;
                        }
                        if (lens[i][j] > max_len) {
                            max_len = lens[i][j];
                        }
                    }
                } else {
                    lens[i][j] = 0;
                }
            }
        }
//        for (int i = 0; i < max_rows; ++i) {
//            for (int j = 0; j < max_cols; ++j) {
//                cout << matrix[i][j] << " ";
//            }
//            cout << endl;
//        }
//        cout << endl;
//        for (int i = 0; i < max_rows; ++i) {
//            for (int j = 0; j < max_cols; ++j) {
//                cout << lens[i][j] << " ";
//            }
//            cout << endl;
//        }
        return max_len * max_len;
    }
};

int main() {
    Solution obj;
    auto run = [&](vector<vector<char>> matrix)->void {
        cout << obj.maximalSquare(matrix) << endl;
    };

    run({{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}});
    run({{'0','0','0','1'},{'1','1','0','1'},{'1','1','1','1'},{'0','1','1','1'},{'0','1','1','1'}});
    return 0;
}
