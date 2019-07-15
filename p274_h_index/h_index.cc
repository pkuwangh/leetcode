/**
 * Given an array of citations (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.
 * According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each,
 * and the other N − h papers have no more than h citations each."
 * Example:
 * Input: citations = [3,0,6,1,5]
 * Output: 3 
 * Explanation: [3,0,6,1,5] means the researcher has 5 papers in total and each of them had 
 *              received 3, 0, 6, 1, 5 citations respectively. 
 *              Since the researcher has 3 papers with at least 3 citations each and the remaining 
 *              two with no more than 3 citations each, her h-index is 3.
 * Note: If there are several possible values for h, the maximum one is taken as the h-index
*/

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int hIndex(vector<int>& citations) {
        map<int, int> num_papers;
        for (const auto& n : citations) {
            if (num_papers.count(n) > 0) {
                ++ num_papers[n];
            } else {
                num_papers[n] = 1;
            }
        }
        int count = 0;
        for (auto it = num_papers.rbegin(); it != num_papers.rend(); ++it) {
            count += it->second;
            if (it->first < count) {
                // # of citation below # of papers
                return max(it->first, count - it->second);
            }
        }
        return count;
    }
};

int main() {
    Solution obj;
    auto run = [&](vector<int> citations)->void {
        for (auto &n : citations) {
            cout << n << " ";
        }
        cout << endl;
        cout << obj.hIndex(citations) << endl;
    };
    run({3,0,6,1,5});
    run({100});
    run({1,1});
    return 0;
}
