/**
 * We have jobs: difficulty[i] is the difficulty of the ith job, and profit[i] is the profit of the ith job. 
 * Now we have some workers. worker[i] is the ability of the ith worker, which means that this worker can only complete a job with difficulty at most worker[i]. 
 * Every worker can be assigned at most one job, but one job can be completed multiple times.
 * For example, if 3 people attempt the same job that pays $1, then the total profit will be $3.  If a worker cannot complete any job, his profit is $0.
 * What is the most profit we can make?
 * Example 1:
 * Input: difficulty = [2,4,6,8,10], profit = [10,20,30,40,50], worker = [4,5,6,7]
 * Output: 100 
 * Explanation: Workers are assigned jobs of difficulty [4,4,6,6] and they get profit of [20,20,30,30] seperately.
 * Notes:
 * 1 <= difficulty.length = profit.length <= 10000
 * 1 <= worker.length <= 10000
 * difficulty[i], profit[i], worker[i]  are in range [1, 10^5]
 */

#include <cassert>
#include <cstdint>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <list>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <functional>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        // build a map
        map<int, int, greater<int>> jobs;
        for (int i = 0; i < profit.size(); ++i) {
            if (jobs.count(profit[i]) > 0) {
                jobs[profit[i]] = min(jobs[profit[i]], difficulty[i]);
            } else {
                jobs[profit[i]] = difficulty[i];
            }
        }
        // sort the workers
        sort(worker.begin(), worker.end(), greater<int>());
        // avoid repeated scan of jobs
        auto iter = jobs.begin();
        int sum = 0;
        for (int i = 0; i < worker.size(); ++i) {
            while (iter != jobs.end()) {
                if (iter->second <= worker[i]) {
                    // can do this work
                    sum += iter->first;
                    break;
                }
                ++ iter;
            }
        }
        return sum;
    }
};

int main() {
    Solution obj;
    auto run = [&](vector<int> difficulty, vector<int> profit, vector<int> worker) ->void {
        cout << obj.maxProfitAssignment(difficulty, profit, worker) << endl;
    };
    run({2,4,6,8,10}, {10,20,30,40,50}, {4,5,6,7});
    return 0;
}
