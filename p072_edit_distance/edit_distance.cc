/* Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.
 * You have the following 3 operations permitted on a word:
 *    Insert a character
 *    Delete a character
 *    Replace a character
 *
 * Example 1:
 * Input: word1 = "horse", word2 = "ros"
 * Output: 3
 * Explanation: 
 * horse -> rorse (replace 'h' with 'r')
 * rorse -> rose (remove 'r')
 * rose -> ros (remove 'e')
 * 
 * Example 2:
 * Input: word1 = "intention", word2 = "execution"
 * Output: 5
 * Explanation: 
 * intention -> inention (remove 't')
 * inention -> enention (replace 'i' with 'e')
 * enention -> exention (replace 'n' with 'x')
 * exention -> exection (replace 'n' with 'c')
 * exection -> execution (insert 'u')
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int minDistance(string word1, string word2) {
        // 2-D dynamic programming
        // why 2-D? two strings w/ variable length
        const int n1 = word1.length();
        const int n2 = word2.length();
        // dist[i][j] represent the edit distance b/w word1[0:i) and word2[0:j)
        // so dist[n1][n2] is the problem itself
        vector<vector<int>> dist(n1+1, vector<int>(n2+1, 0));
        // init
        for (int i = 0; i <= n1; ++i) {
            // word2 is empty
            dist[i][0] = i;
        }
        for (int j = 0; j <= n2; ++j) {
            // word1 is empty
            dist[0][j] = j;
        }
        // push to right bottom
        for (int i = 1; i <= n1; ++i) {
            for (int j = 1; j <= n2; ++j) {
                // 3 options for dist[i][j]
                // from dist[i][j-1], i.e. word1[0:i] -> word2[0:j-1], insert one char
                int ins = dist[i][j-1] + 1;
                // from dist[i-1][j], i.e. word1[0:i-1] -> word2[0:j], delete one char
                int del = dist[i-1][j] + 1;
                // from dist[i-1][j-1], i.e. word[0:i-1][0:j-1], try to replace one char
                int rep = (word1[i-1] == word2[j-1]) ? dist[i-1][j-1] : dist[i-1][j-1] + 1;
                // pick the smallest
                dist[i][j] = min(min(ins, del), rep);
            }
        }
        return dist[n1][n2];
    }
};

int main() {
    Solution obj;
    cout << obj.minDistance("horse", "ros") << endl;
    cout << obj.minDistance("intention", "execution") << endl;
    return 0;
}
