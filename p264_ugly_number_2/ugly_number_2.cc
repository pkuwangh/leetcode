/**
 * Write a program to find the n-th ugly number.
 * Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 
 * Example:
 * Input: n = 10
 * Output: 12
 * Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
 * Note:  
 * 1 is typically treated as an ugly number.
 * n does not exceed 1690.
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
#include <functional>
#include <algorithm>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

class Solution {
  public:
    bool checkNum(const int& num, const unordered_set<int>& ugly_nums) {
        if (num == 1) return true;
        if (num % 2 == 0 && ugly_nums.count(num/2) > 0) return true;
        if (num % 3 == 0 && ugly_nums.count(num/3) > 0) return true;
        if (num % 5 == 0 && ugly_nums.count(num/5) > 0) return true;
        return false;
    }

    int nthUglyNumber(int n) {
        set<uint64_t, less<uint64_t>> ugly_seeds;
        ugly_seeds.insert(1);
        uint64_t num = 0;
        for (int i = 1; i <= n; ++i) {
            num = *(ugly_seeds.begin());
            // push into new seeds
            ugly_seeds.insert(num*2);
            ugly_seeds.insert(num*3);
            ugly_seeds.insert(num*5);
            ugly_seeds.erase(ugly_seeds.begin());
        }
        return num;

//        unordered_set<int> ugly_nums;
//        int num = 0;
//        for (int i = 0; i < n; ++i) {
//            do {
//                ++ num;
//            } while (!checkNum(num, ugly_nums));
//            ugly_nums.insert(num);
//        }
//        return num;
    }
};

int main() {
    Solution obj;
    auto run = [&](int n) ->void {
        cout << n << " -> " << obj.nthUglyNumber(n) << endl;
    };
    run(1);
    run(10);
    run(800);
    run(1689);
    return 0;
}
