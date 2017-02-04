/* There are N gas stations along a circular route,
 * where the amount of gas at station i is gas[i].
 * You have a car with an unlimited gas tank and it costs cost[i] of gas
 * to travel from station i to its next station (i+1).
 * You begin the journey with an empty tank at one of the gas stations.
 * Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
 * Note:
 * The solution is guaranteed to be unique.
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int size = gas.size();
        int start = 0;
        while (start < size) {
            int remaining_gas = 0;
            int i = 0;
            for (i = 0; i < size; ++i) {
                int idx = (start + i) % size;
                remaining_gas += (gas[idx] - cost[idx]);
                if (remaining_gas < 0) break;
            }
            if (i == size) {
                return start;
            }
            start += (i+1);
        }
        return -1;
    }
};

int main() {
    Solution obj;
    vector<int> gas({1, 2});
    vector<int> cost({2, 1});
    cout << obj.canCompleteCircuit(gas, cost) << endl;
    return 0;
}

