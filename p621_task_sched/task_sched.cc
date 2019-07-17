/**
 * Given a char array representing tasks CPU need to do.
 * It contains capital letters A to Z where different letters represent different tasks.
 * Tasks could be done without original order. Each task could be done in one interval.
 * For each interval, CPU could finish one task or just be idle.
 * However, there is a non-negative cooling interval n that means between two same tasks, there must be at least n intervals that CPU are doing different tasks or just be idle.
 * You need to return the least number of intervals the CPU will take to finish all the given tasks.
 * Example:
 * Input: tasks = ["A","A","A","B","B","B"], n = 2
 * Output: 8
 * Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
 * Note:
 * The number of tasks is in the range [1, 10000].
 * The integer n is in the range [0, 100].
*/

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
  public:
    int leastInterval(vector<char>& tasks, int n) {
        const int num_types = 26;
        // count number of jobs of each type
        vector<int> count(num_types, 0);
        for (const auto& c : tasks) {
            count[c - 'A'] += 1;
        }
        // scheduling
        vector<int> cooldown(num_types, 0);
        int num_sched = 0;
        int num_interval = 0;
        while (num_sched < tasks.size()) {
            int job_to_sched = -1;
            for (int i = 0; i < num_types; ++i) {
                if (count[i] > 0) {
                    if (cooldown[i] > 0) {
                        cooldown[i] -= 1;
                    } else {
                        // eligible to schedule
                        if (job_to_sched < 0 || count[job_to_sched] < count[i]) {
                            job_to_sched = i;
                        }
                    }
                }
            }
            // track cooldown count-down
            if (job_to_sched >= 0) {
                num_sched += 1;
                cooldown[job_to_sched] = n;
                count[job_to_sched] -= 1;
            }
            ++ num_interval;
        }
        return num_interval;
    }
};

int main() {
    Solution obj;
    auto run = [&](vector<char> tasks, int n) {
        for (auto& c : tasks) {
            cout << c << " ";
        }
        cout << endl << "n=" << n << ": ";
        cout << obj.leastInterval(tasks, n) << endl;
    };
    run({'A','A','A','B','B','B'}, 2);
    return 0;
}
