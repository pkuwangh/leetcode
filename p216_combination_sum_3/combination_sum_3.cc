/* Find all possible combinations of k numbers that add up to a number n,
 * given that only numbers from 1 to 9 can be used and
 * each combination should be a unique set of numbers.
 * Example 1:
 * Input: k = 3, n = 7
 * Output:
 * [[1,2,4]]
 * Example 2:
 * Input: k = 3, n = 9
 * Output:
 * [[1,2,6], [1,3,5], [2,3,4]]
 */

#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
  public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> all_sols;
        vector<int> sol;
        set<int> nums({1,2,3,4,5,6,7,8,9});
        findSols(all_sols, sol, nums, k, n);
        return all_sols;
    }

    void findSols(vector<vector<int>>& all_sols, vector<int>& sol, set<int> nums, int k, int n)
    {
        if (k == 0) {
            if (n == 0) {
                all_sols.push_back(sol);
            }
            return;
        }
        set<int> new_nums = nums;
        for (auto &num : nums) {
            // pick num
            sol.push_back(num);
            new_nums.erase(num);
            // recursion
            findSols(all_sols, sol, new_nums, k-1, n-num);
            // roll back
            sol.pop_back();
        }
    }
};

int main() {
    Solution obj;
    auto ans = obj.combinationSum3(3, 9);
    for (auto& vec : ans) {
        cout << "[ ";
        for (auto &n : vec) {
            cout << n << " ";
        }
        cout << " ]" << endl;
    }
    return 0;
}
