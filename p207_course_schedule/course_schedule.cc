/* There are a total of n courses you have to take, labeled from 0 to n-1.
 * Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
 * Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?
 * Example 1:
 * Input: 2, [[1,0]]
 * Output: true
 * Explanation: There are a total of 2 courses to take.
 * To take course 1 you should have finished course 0. So it is possible.
 *
 * Example 2:
 * Input: 2, [[1,0],[0,1]]
 * Output: false
 * Explanation: There are a total of 2 courses to take.
 * To take course 1 you should have finished course 0, and to take course 0 you should
 * also have finished course 1. So it is impossible.
 * Note:
 * The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
 * You may assume that there are no duplicate edges in the input prerequisites.
 */

#include <cassert>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
  public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // build the graph
        vector<set<int>> graph(numCourses);
        for (const auto& edge : prerequisites) {
            graph[edge[1]].insert(edge[0]);
        }
        // detect cycles
        set<int> white_set;
        for (int i = 0; i < numCourses; ++i) {
            white_set.insert(i);
        }
        set<int> gray_set;
        set<int> black_set;
        // dfs
        for (int i = 0; i < numCourses; ++i) {
            if (white_set.count(i) > 0) {
                // in white set
                if (dfs(graph, i, white_set, gray_set, black_set)) {
                    // there is a cycle
                    return false;
                }
            }
        }
        return true;
    }

    bool dfs(const vector<set<int>>& graph, int n,
            set<int>& white_set, set<int>& gray_set, set<int>& black_set) {
        // remove from white set, put into gray set
        white_set.erase(n);
        gray_set.insert(n);
        // scan each outgoing edge
        for (const auto& x : graph[n]) {
            if (white_set.count(x) > 0) {
                // recursive dfs
                if (dfs(graph, x, white_set, gray_set, black_set)) {
                    return true;
                }
            } else if (gray_set.count(x) > 0) {
                return true;
            } else {
                // in black set
                assert(black_set.count(x) > 0);
                continue;
            }
        }
        // remove from gray set, put into black set
        gray_set.erase(n);
        black_set.insert(n);
        return false;
    }
};

int main() {
    Solution obj;
    auto run = [&](int num, vector<vector<int>> prereq)->void {
        cout << obj.canFinish(num, prereq) << endl;
    };
    run(2, {{1,0}});
    run(2, {{1,0}, {0,1}});
    return 0;
}
