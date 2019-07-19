/**
 * Given an array of citations sorted in ascending order (each citation is a non-negative integer) of a researcher,
 * write a function to compute the researcher's h-index.
 * According to the definition of h-index on Wikipedia:
 * "A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each."
 * Example:
 * Input: citations = [0,1,3,5,6]
 * Output: 3 
 * Explanation: [0,1,3,5,6] means the researcher has 5 papers in total and each of them had 
 *              received 0, 1, 3, 5, 6 citations respectively. 
 *              Since the researcher has 3 papers with at least 3 citations each and the remaining 
 *              two with no more than 3 citations each, her h-index is 3.
 * Note:
 * If there are several possible values for h, the maximum one is taken as the h-index.
 * Follow up:
 * This is a follow up problem to H-Index, where citations is now guaranteed to be sorted in ascending order.
 * Could you solve it in logarithmic time complexity?
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
#include <algorithm>
using namespace std;

class Solution {
  public:
    int hIndex(vector<int>& citations) {
        if (citations.size() == 0) return 0;
        return hIndex_bin(citations, 0, citations.size()-1);
    }

    int hIndex_bin(const vector<int>& citations, int low, int high) {
        if (low == high) {
            const int h_index = citations.size() - low;
            if (citations[low] >= h_index) {
                return h_index;
            } else {
                return 0;
            }
        }
        const int mid = (low + high) / 2;
        const int num_papers = citations.size() - mid;
        const int num_citations = citations[mid];
        if (num_citations >= num_papers) {
            // not equal condition, because there is possibly larger h
            return hIndex_bin(citations, low, mid);
        } else {
            return hIndex_bin(citations, mid+1, high);
        }
    }
};

int main() {
    Solution obj;
    auto run = [&](vector<int> citations) ->void {
        for_each(citations.begin(), citations.end(), [](int& n)->void { cout << n << " "; });
        cout << endl;
        cout << obj.hIndex(citations) << endl;
    };
    run({0,1,3,5,6});
    run({0});
    return 0;
}
