/* The string "PAYPALISHIRING" is written in a zigzag pattern
 * on a given number of rows like this:
 * (you may want to display this pattern in a fixed font for better legibility)
 *
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * And then read line by line: "PAHNAPLSIIGYIR"
 * Write the code that will take a string and make this conversion given a number of rows:
 *
 * string convert(string text, int nRows);
 * convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// matrix transpose
class Solution {
  public:
    string convert(string s, int numRows) {
        vector<string> str_matrix(numRows);
        // calculate the row index for each element
        int period = 2 * numRows - 2;
        for (int i = 0; i < (int)s.length(); ++i) {
            int idx = (period > 0) ? (i % period) : 0;
            int row_idx = (idx >= numRows) ? (period - idx) : idx;
            str_matrix[row_idx].push_back(s[i]);
        }
        // convert to result string
        string res(s.size(),  ' ');
        int k = 0;
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < (int)str_matrix[i].length(); ++j) {
                res[k++] = str_matrix[i][j];
            }
        }
        return res;
    }
};

int main()
{
    Solution obj;

    cout << obj.convert("PAYPALISHIRING", 3) << endl;
    cout << obj.convert("PAYPALISHIRING", 1) << endl;

    return 0;
}
