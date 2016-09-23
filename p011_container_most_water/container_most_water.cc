/* Given n non-negative integers a1, a2, ..., an,
 * where each represents a point at coordinate (i, ai).
 * n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
 * Find two lines, which together with x-axis forms a container,
 * such that the container contains the most water.
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    // two pointers
    int maxArea(vector<int>& height) {
        int area = 0;
        int max_area = 0;
        int left = 0;
        int right = height.size() - 1;

        while (right > left) {
            if (height[left] < height[right]) {
                area = (right - left) * height.at(left);
                // for any i < right, S(left, i) <= S(left, right)
                ++ left;
            } else {
                area = (right - left) * height.at(right);
                -- right;
            }

            if (max_area < area) {
                max_area = area;
            }
        }
        return max_area;
    }

    // prune search space, still O(N^2) in worst case
    /*
    int maxArea(vector<int>& height) {
        int max_area = 0;
        int max_height = 0;
        for (size_t b = 0; b < height.size() - 1; ++b) {
            if (max_height < height[b]) {
                max_height = height[b];
            } else {
                continue;
            }
            for (size_t e = b + 1; e < height.size(); ++e) {
                int area = (e - b) * (height[e] < height[b] ? height[e] : height[b]);
                if (max_area < area) {
                    max_area = area;
                }
            }
        }
        return max_area;
    }
    */

    // O(N^2) brute force
    /*
    int maxArea(vector<int>& height) {
        int max_area = 0;
        for (size_t b = 0; b < height.size() - 1; ++b) {
            for (size_t e = b + 1; e < height.size(); ++e) {
                int area = (e - b) * (height[e] < height[b] ? height[e] : height[b]);
                if (max_area < area) {
                    max_area = area;
                }
            }
        }
        return max_area;
    }
    */
};

int main() {
    Solution obj;

    vector<int> test1 = {2, 3, 4};

    vector<int> test2(15000);
    for (size_t i = 0; i < test2.size(); ++i) {
        test2[i] = i + 1;
    }

    vector<int> test3 = {1, 1};

    auto run = [&](vector<int> &test) ->void {
        if (test.size() <= 10) {
            for_each(test.begin(), test.end(), [](int &n)->void { cout << n << " "; });
            cout << endl;
        }
        clock_t start = clock();
        cout << obj.maxArea(test) << endl;
        double duration = (clock() - start) / (double) CLOCKS_PER_SEC;
        cout << "Elapsed time: " << duration << endl;
    };

    run(test1);
    run(test2);
    run(test3);

    return 0;
}
