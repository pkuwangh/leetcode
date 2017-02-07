/* There are N children standing in a line. Each child is assigned a rating value.
 * You are giving candies to these children subjected to the following requirements:
 * Each child must have at least one candy.
 * Children with a higher rating get more candies than their neighbors.
 * What is the minimum candies you must give?
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int candy(vector<int>& ratings) {
        int size = ratings.size();
        // 1. init to all 1
        vector<int> num(size, 1);
        // 2. forward scan
        for(int i = 0; i < size-1; ++i) {
            if (ratings[i+1] > ratings[i]) {
                num[i+1] = num[i] + 1;
            }
        }
        // 3. backward scan
        for (int i = size-1; i > 0; --i) {
            if (ratings[i-1] > ratings[i] && num[i-1] <= num[i]) {
                num[i-1] = num[i] + 1;
            }
        }
        int sum = 0;
        for_each(num.begin(), num.end(), [&sum](int &n)->void { sum += n; });
        return sum;
    }
};

int main() {
    Solution obj;
    vector<int> ratings({1, 2, 3, 4, 3, 1});   // 1+2+3+4+2+1 = 13
    cout << obj.candy(ratings) << endl;
    return 0;
}
