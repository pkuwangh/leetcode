/* Given n non-negative integers representing the histogram's bar height
 * where the width of each bar is 1, find the area of largest rectangle in the histogram.
 *
 * For example,
 * Given heights = [2,1,5,6,2,3],
 * return 10.
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <initializer_list>
using namespace std;

class Solution {
  public:
    int largestRectangleArea(vector<int>& heights) {
        // keep a stack
        stack<pair<int, int>> index;  // starting index, height
        index.push(make_pair(-1, 0)); // add a dummy point at the beginning
        heights.push_back(0);
        int max_area = 0;
        for (int i = 0; i < (int)heights.size(); ++i) {
            int h = heights[i];
            auto top = index.top();
            if (h >= top.second) {
                // the height is increasing, push to stack
                index.push(make_pair(i, h));
            } else {
                // the height is decreasing, bars in stack cannot extend to i
                int left = i;
                while (!index.empty() && h < index.top().second) {
                    left = index.top().first;
                    int area = (i - left) * index.top().second;
                    if (max_area < area) {
                        max_area = area;
                    }
                    index.pop();
                }
                // push to stack
                index.push(make_pair(left, h));
            }
        }
        heights.pop_back();
        return max_area;
    }
};

int main() {
    Solution obj;
    auto run = [&obj](initializer_list<int> init_list)->void {
        vector<int> heights(init_list);
        for_each(heights.begin(), heights.end(), [](int &n)->void {cout << n << " ";});
        cout << endl;
        cout << obj.largestRectangleArea(heights) << endl;
    };

    run({2, 1, 5, 6, 2, 3});
    run({7});
    run({});
    run({1, 1});
    run({2, 1, 2});
    run({4, 2, 0, 3, 2, 5});

    return 0;
}
