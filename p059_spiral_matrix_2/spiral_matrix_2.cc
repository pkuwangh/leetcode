/* Given an integer n,
 * generate a square matrix filled with elements from 1 to n2 in spiral order.
 * For example,
 * Given n = 3,
 * You should return the following matrix:
 * [
 *  [ 1, 2, 3 ],
 *  [ 8, 9, 4 ],
 *  [ 7, 6, 5 ]
 * ]
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int num_level = (n+1)/2;
        int num = 1;
        for (int i = 0; i < num_level; ++i) {
            int last = n-1-i;
            if (i == last) matrix[i][i] = (num++);
            for (int j = i; j < last; ++j) matrix[i][j] = (num++);
            for (int j = i; j < last; ++j) matrix[j][last] = (num++);
            for (int j = last; j > i; --j) matrix[last][j] = (num++);
            for (int j = last; j > i; --j) matrix[j][i] = (num++);
        }
        return matrix;
    }
};

int main() {
    Solution obj;
    auto matrix = obj.generateMatrix(4);
    for (auto &row : matrix) {
        for (auto &n : row) {
            cout << n << " ";
        }
        cout << endl;
    }
    return 0;
}
