/* Given an unsorted array of integers,
 * find the length of the longest consecutive elements sequence.
 * For example,
 * Given [100, 4, 200, 1, 3, 2],
 * The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
 * Your algorithm should run in O(n) complexity.
 */

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
  public:
    int longestConsecutive(vector<int>& nums) {
        // hash table
        unordered_set<int> ht;
        for (auto &n : nums) {
            ht.insert(n);
        }
        // pop from hash table
        int max_cnt = 0;
        while (!ht.empty()) {
            int cnt = 0;
            int n = *(ht.begin());
            int diff = 0;
            while (ht.count(n+diff)) {
                ++ cnt;
                ht.erase(n+diff);
                ++ diff;
            }
            diff = 1;
            while (ht.count(n-diff)) {
                ++ cnt;
                ht.erase(n-diff);
                ++ diff;
            }
            max_cnt = (max_cnt < cnt) ? cnt : max_cnt;
        }
        return max_cnt;
    }
};

int main() {
    Solution obj;
    auto run = [&](vector<int> nums) { cout << obj.longestConsecutive(nums) << endl; };
    run({100, 4, 200, 1, 3, 2});
    return 0;
}
