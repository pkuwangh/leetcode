/* Given a matrix of m x n elements (m rows, n columns),
 * return all elements of the matrix in spiral order.
 * For example,
 * Given the following matrix:
 * [
 *  [ 1, 2, 3 ],
 *  [ 4, 5, 6 ],
 *  [ 7, 8, 9 ]
 * ]
 * You should return [1,2,3,6,9,8,7,4,5].
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        if(matrix.empty() || matrix[0].empty()) return ret;
        int m = matrix.size(), n = matrix[0].size();
        int nlvl = (min(m,n)+1)/2;    // number of levels
        for(int i=0; i<nlvl; i++) {
            int lastRow = m-1-i;  // mirrored last row
            int lastCol = n-1-i;  // mirrored last col
            if(lastRow==i) {    // one row remain
                for(int j=i; j<=lastCol; j++) ret.push_back(matrix[i][j]);
            } else if(lastCol==i) {   // one col remain
                for(int j=i; j<=lastRow; j++) ret.push_back(matrix[j][i]);
            } else {
                for(int j=i; j<lastCol; j++) ret.push_back(matrix[i][j]      );
                for(int j=i; j<lastRow; j++) ret.push_back(matrix[j][lastCol]);
                for(int j=lastCol; j>i; j--) ret.push_back(matrix[lastRow][j]);
                for(int j=lastRow; j>i; j--) ret.push_back(matrix[j][i]      );
            }
        }
        return ret;
    }
};

int main() {
    Solution obj;
    vector<int> row1({0, 1, 2, 3});
    vector<int> row2({4, 5, 6, 7});
    vector<int> row3({8, 9, 10, 11});
    vector<vector<int>> matrix({row1, row2, row3});
    auto ans = obj.spiralOrder(matrix);
    for_each(ans.begin(), ans.end(), [](int& n)->void{ cout << n << " "; });
    cout << endl;
    return 0;
}
