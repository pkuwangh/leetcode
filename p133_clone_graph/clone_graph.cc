/* Clone an undirected graph.
 * Each node in the graph contains a label and a list of its neighbors.
 * OJ's undirected graph serialization:
 * Nodes are labeled uniquely.
 * We use # as a separator for each node,
 * and , as a separator for node label and each neighbor of the node.
 * As an example, consider the serialized graph {0,1,2#1,2#2,2}.
 * The graph has a total of three nodes, and therefore contains three parts as separated by #.
 * First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
 * Second node is labeled as 1. Connect node 1 to node 2.
 * Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
 * Visually, the graph looks like the following:
 *        1
 *       / \
 *      /   \
 *     0 --- 2
 *          / \
 *          \_/
 */

#include <vector>
#include <queue>
#include <map>
#include <iostream>
using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
  public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL) return NULL;
        using GraphNode = UndirectedGraphNode;
        // BFS; build a map along the way
        queue<GraphNode*> node_queue;
        node_queue.push(node);
        map<GraphNode*, GraphNode*> node_map;
        node_map[node] = new GraphNode(node->label);
        while (!node_queue.empty()) {
            // pop a node from queue
            auto src_node = node_queue.front();
            auto dst_node = node_map[src_node];
            node_queue.pop();
            // iterate through the neighbor list
            for (auto& src_nb : src_node->neighbors) {
                if (node_map.count(src_nb)) {
                    dst_node->neighbors.push_back(node_map[src_nb]);
                } else {
                    GraphNode* dst_nb = new GraphNode(src_nb->label);
                    dst_node->neighbors.push_back(dst_nb);
                    // add to map and queue
                    node_map[src_nb] = dst_nb;
                    node_queue.push(src_nb);
                }
            }
        }
        return node_map[node];
    }
};

int main() {
    Solution obj;
    UndirectedGraphNode *node = new UndirectedGraphNode(-1);
    auto ans = obj.cloneGraph(node);
    cout << ans->label << endl;
    return 0;
}
