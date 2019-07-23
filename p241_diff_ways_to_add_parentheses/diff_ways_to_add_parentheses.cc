/**
 * Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators.
 * The valid operators are +, - and *.
 * Example 1:
 * Input: "2-1-1"
 * Output: [0, 2]
 * Explanation: 
 * ((2-1)-1) = 0 
 * (2-(1-1)) = 2
 * Example 2:
 * Input: "2*3-4*5"
 * Output: [-34, -14, -10, -10, 10]
 * Explanation: 
 * (2*(3-(4*5))) = -34 
 * ((2*3)-(4*5)) = -14 
 * ((2*(3-4))*5) = -10 
 * (2*((3-4)*5)) = -10 
 * (((2*3)-4)*5) = 10
 */

#include <cassert>
#include <cstdint>
#include <iostream>
#include <functional>
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
    vector<int> diffWaysToCompute(string input) {
        return ways(input);
    }

    vector<int> ways(const string& input) {
        // Already solved, return the answer
        if(cache_.count(input) > 0) return cache_[input];

        vector<int> ans;
        // break the at each operator
        for(unsigned i = 0; i < input.length(); ++i) {
            // Split the input by an op
            if(input[i]=='+' || input[i]=='-' || input[i]=='*') {
                // recursively get result vector of sub strings
                const string left = input.substr(0, i);
                const string right = input.substr(i+1);
                const vector<int>& l = ways(left);
                const vector<int>& r = ways(right);

                auto add =  [](int a, int b)->int { return a + b; };
                auto sub =  [](int a, int b)->int { return a - b; };
                auto mult = [](int a, int b)->int { return a * b; };
                std::function<int(int,int)> f;
                switch(input[i]) {
                    case '+': f = add;  break;
                    case '-': f = sub;  break;
                    case '*': f = mult; break;
                }
                // combine the solutions
                for(int a : l) {
                    for(int b : r) {
                        ans.push_back(f(a,b));
                    }
                }
            }
        }
        // single number, e.g. s = "3"
        if(ans.empty()) {
            ans.push_back(std::stoi(input));
        }
        // cache/memorize the answer for input
        cache_[input] = ans;
        return cache_[input];
    }

    unordered_map<string, vector<int>> cache_;
};

int main() {
    Solution obj;
    auto run = [&](string input) ->void {
        cout << input << endl;
        auto ans = obj.diffWaysToCompute(input);
        for (auto& x : ans) {
            cout << x << " ";
        }
        cout << endl;
    };
    run("2-1-1");
    run("2*3-4*5");
    return 0;
}
