/* Given an index k, return the kth row of the Pascal's triangle.
 * For example, given k = 3,
 * [
 *       [1],
 *      [1,1],
 *     [1,2,1],
 *    [1,3,3,1],
 *   [1,4,6,4,1]
 * ]
 * Return [1,3,3,1].
 * Note:
 * Could you optimize your algorithm to use only O(k) extra space?
 *
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> getRow(int rowIndex) {
        int numCols = rowIndex + 1;
        vector<vector<int>> rows(2, vector<int>(numCols, 0));
        int src = 0;
        int dst = 1;
        rows[src][0] = 1;
        for (int i = 1; i <= rowIndex; ++i) {
            rows[dst][0] = 1;
            rows[dst][i] = 1;
            for (int j = 1; j < i; ++j) {
                rows[dst][j] = rows[src][j-1] + rows[src][j];
            }
            src = dst;
            dst = 1 - src;
        }
        return rows[src];
    }
};

int main() {
    Solution obj;
    auto row = obj.getRow(3);
    for (const auto & n : row) {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}
