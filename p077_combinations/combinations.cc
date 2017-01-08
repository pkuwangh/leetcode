/* Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
 * For example,
 * If n = 4 and k = 2, a solution is:
 * [
 *   [2,4],
 *   [3,4],
 *   [2,3],
 *   [1,2],
 *   [1,3],
 *   [1,4],
 * ]
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> all_sols;
        vector<int> sol(k, 0);
        vector<int> nums(n, 0);
        for (int i = 0; i < n; ++i) {
            nums[i] = i+1;
        }
        findCombination(all_sols, sol, nums, k);
        return all_sols;
    }

    void findCombination(vector<vector<int>>& all_sols, vector<int>& sol,
                         vector<int> nums, int k)
    {
        for (unsigned int i = 0; i < nums.size(); ++i) {
            // check in
            sol.at(k-1) = nums[i];
            if (k == 1) {
                // find a solution
                all_sols.push_back(sol);
            } else {
                // construct new candidate vector
                int size = nums.size() - i - 1;
                if (size >= k-1) {
                    vector<int> new_nums(size, 0);
                    for (int j = 0; j < size; ++j) {
                        new_nums[j] = nums[i+1+j];
                    }
                    findCombination(all_sols, sol, new_nums, k-1);
                }
            }
        }
    }
};

int main() {
    Solution obj;
    auto ans = obj.combine(4, 2);
    for (auto &vec : ans) {
        for (auto &n : vec) {
            cout << n << " ";
        }
        cout << endl;
    }
    return 0;
}
