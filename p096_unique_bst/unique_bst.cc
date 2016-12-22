/* Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
 *
 * For example,
 * Given n = 3, there are a total of 5 unique BST's.
 *
 *    1         3     3      2      1
 *     \       /     /      / \      \
 *      3     2     1      1   3      2
 *     /     /       \                 \
 *    2     1         2                 3
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int numTrees(int n) {
        vector<int> num(n+1, 0);
        num[0] = 1;
        num[1] = 1;
        for (int i = 2; i <= n; ++i) {
            // when having i nodes
            for (int j = 0; j < i; ++j) {
                // when putting j as the root
                // j left nodes, i-1-j right nodes
                num[i] += num[j] * num[i-1-j];
            }
        }
        return num[n];
    }
};

int main() {
    Solution obj;
    for (uint32_t i = 1; i < 5; ++i) {
        cout << obj.numTrees(i) << endl;
    }
    return 0;
}
