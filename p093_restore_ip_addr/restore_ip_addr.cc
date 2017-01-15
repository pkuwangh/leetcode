/* Given a string containing only digits,
 * restore it by returning all possible valid IP address combinations.
 * For example:
 * Given "25525511135",
 * return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> all_sols;
        vector<string> sol(4, "");
        findIp(all_sols, sol, 0, s, 0);
        return all_sols;
    }

    void findIp(vector<string>& all_sols, vector<string>& sol, size_t num, string &s, size_t start) {
        if (num == 4 || start == s.size()) {
            if (num == 4 && start == s.size()) {
                // found a solution
                string sol_str;
                for (size_t i = 0; i < num-1; ++i) {
                    sol_str += (sol[i] + '.');
                }
                sol_str += sol[num-1];
                all_sols.push_back(sol_str);
            }
            return;
        }

        int one = -1;
        if (start < s.size()) one = s[start]-'0';
        int two = -1;
        if (start+1 < s.size()) two = one*10 + s[start+1]-'0';
        int three = -1;
        if (start+2 < s.size()) three = two*10 + s[start+2]-'0';

        if (one >= 0) {
            sol.at(num) = to_string(one);
            findIp(all_sols, sol, num+1, s, start+1);
        }
        if (two >= 10) {
            sol.at(num) = to_string(two);
            findIp(all_sols, sol, num+1, s, start+2);
        }
        if (three >= 100 && three <= 255) {
            sol.at(num) = to_string(three);
            findIp(all_sols, sol, num+1, s, start+3);
        }
    }
};

int main() {
    Solution obj;
    auto ans = obj.restoreIpAddresses("25525511135");
//    auto ans = obj.restoreIpAddresses("1111");
    for (auto &addr : ans) { cout << addr << endl; }
    return 0;
}
