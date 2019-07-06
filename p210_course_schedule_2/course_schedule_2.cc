/* There are a total of n courses you have to take, labeled from 0 to n-1.
 * Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
 * Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.
 * There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.
 *    Example 1:
 * Input: 2, [[1,0]]
 * Output: [0,1]
 * Explanation: There are a total of 2 courses to take. To take course 1 you should have finished
 *              course 0. So the correct course order is [0,1] .
 *              Example 2:
 * Input: 4, [[1,0],[2,0],[3,1],[3,2]]
 * Output: [0,1,2,3] or [0,2,1,3]
 * Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both
 *              courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
 *                           So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3] .
 * Note:
 * The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
 * You may assume that there are no duplicate edges in the input prerequisites.
 */

#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdint>
using namespace std;

class Solution {
  public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> order(numCourses, -1);
        int num = 0;
        // build graph
        vector<set<int>> graph(numCourses);
        for (const auto& edge : prerequisites) {
            graph[edge[1]].insert(edge[0]);
        }
        // dfs
        // state tracker: 0-unvisited, 1-visiting, 2-done
        vector<int> state(numCourses, 0);
        for (int i = 0; i < numCourses; ++i) {
            if (state[i] == 0) {
                // dfs
                if (dfs(graph, i, state, order, num)) {
                    return {};
                }
            }
        }
        return order;
    }

    bool dfs(const vector<set<int>>& graph, int n, vector<int>& state,
            vector<int>& order, int& num)
    {
        // move from unvisited to visiting
        state[n] = 1;
        // scan its children
        for (const auto& x : graph[n]) {
            if (state[x] == 0) {
                if (dfs(graph, x, state, order, num)) {
                    return true;
                }
            } else if (state[x] == 1) {
                return true;
            } else {
                continue;
            }
        }
        // move to done list
        state[n] = 2;
        order[order.size()-1-num] = n;
        ++ num;
        return false;
    }
};

int main() {
    Solution obj;
    auto run = [&](int num, vector<vector<int>> prereqs) {
        cout << num << " courses" << endl;
        for (const auto& req : prereqs) {
            cout << "[" << req[0] << "," << req[1] << "] ";
        }
        cout << endl;
        vector<int> ans = obj.findOrder(num, prereqs);
        cout << "order: [ ";
        for (const auto& x : ans) {
            cout << x << " ";
        }
        cout << "]" << endl;
    };
    run(2, {{1,0}});
    run(3, {{2,0}, {2,1}});
    run(4, {{1,0}, {2,0}, {3,1}, {3,2}});
    return 0;
}
