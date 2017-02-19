/* Given a list of non negative integers, arrange them such that they form the largest number.
 * For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
 * Note: The result may be very large, so you need to return a string instead of an integer.
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        // convert to a vector of strings
        vector<string> str_nums(n, "");
        for (int i = 0; i < n; ++i) {
            str_nums[i] = to_string(nums[i]);
        }
        // sort
        auto comp = [](const string& str1, const string& str2)-> bool {
            string op1 = str1+str2;
            string op2 = str2+str1;
            for (uint32_t i = 0; i < op1.size(); ++i) {
                if (op1[i] > op2[i]) {
                    return true;
                } else if (op1[i] < op2[i]) {
                    return false;
                }
            }
            return false;
        };
        sort(str_nums.begin(), str_nums.end(), comp);
        if (n == 0 || str_nums[0][0] == '0') {
            return string("0");
        }
        string number;
        for (auto &str_num : str_nums) {
            number.append(str_num);
        }
        return number;
    }
};

int main() {
    Solution obj;
    auto run = [&obj](vector<int> nums) {
        cout << obj.largestNumber(nums) << endl;
    };
    run({3, 30, 34, 5, 9});
    run({999999998,999999997,999999999});
    run({824,938,1399,5607,6973,5703,9609,4398,8247});
    run({0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0});
    return 0;
}
