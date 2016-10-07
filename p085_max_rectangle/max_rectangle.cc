/* Given a 2D binary matrix filled with 0's and 1's,
 * find the largest rectangle containing only 1's and return its area.
 *
 * For example, given the following matrix:
 *
 * 1 0 1 0 0
 * 1 0 1 1 1
 * 1 1 1 1 1
 * 1 0 0 1 0
 *
 * Return 6.
 */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

#define DEBUG

class Solution {
  public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return 0;
        }

        int max_area = 0;
        vector<int> heights(matrix[0].size() + 1, 0);
        // scan each row; consider the row as the bottom of a matrix
        for (auto &row : matrix) {
            // calculate the height at each column
            for (int i = 0; i < (int)row.size(); ++i) {
                if (row[i] == '1') {
                    heights[i] += 1;
                } else {
                    heights[i] = 0;
                }
#ifdef DEBUG
                cout << heights[i] << " ";
#endif
            }
#ifdef DEBUG
            cout << endl;
#endif
            // now it reduces to the largest rectangle in histogram problem
            // use a stack to keep left column index and height
            stack<pair<int, int>> bars;
            bars.push(make_pair(-1, 0));
            for (int i = 0; i < (int)row.size() + 1; ++i) {
                if (heights[i] >= bars.top().second) {
                    // the rectangle can be extended to i, so push stack
                    bars.push(make_pair(i, heights[i]));
                } else {
                    // pop stack
                    int left_idx = i;
                    while (!bars.empty() && heights[i] < bars.top().second) {
                        int h = bars.top().second;
                        int k = bars.top().first;
                        bars.pop(); 
                        int area = (i - k) * h;
                        max_area = (max_area < area) ? area : max_area;
                        left_idx = k;
                    }
                    // push stack, note the left column index should be same as last popped
                    bars.push(make_pair(left_idx, heights[i]));
                }
            }
        }
        return max_area;
    }
};

int main() {
    vector<vector<char>> input;
    input.push_back(vector<char>({'1', '0', '1', '0', '0'}));
    input.push_back(vector<char>({'1', '0', '1', '1', '1'}));
    input.push_back(vector<char>({'1', '1', '1', '1', '1'}));
    input.push_back(vector<char>({'1', '0', '0', '1', '0'}));

    Solution obj;
    cout << obj.maximalRectangle(input) << endl;

    return 0;
}
