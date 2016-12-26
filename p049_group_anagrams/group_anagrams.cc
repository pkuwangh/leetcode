/* Given an array of strings, group anagrams together.
 * For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
 * Return:
 * [
 *   ["ate", "eat","tea"],
 *   ["nat","tan"],
 *   ["bat"]
 * ]
 * Note: All inputs will be in lower-case.
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
  public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // map a set of anagrams to same key
        auto getKey = [](string &str) -> string {
            string key = str;
            sort(key.begin(), key.end());
            return key;
        };
        // scan all strings, push into a hash table
        unordered_map<string, vector<unsigned int>> ht;   // key, vector of indices
        for (unsigned int i = 0; i < strs.size(); ++i) {
            ht[getKey(strs[i])].push_back(i);
        }
        // write answers
        vector<vector<string>> groups;
        for (auto it = ht.begin(); it != ht.end(); ++it) {
            if (it->second.size() > 0) {
                vector<string> group;
                for (auto & index : it->second) {
                    group.push_back(strs[index]);
                }
                groups.push_back(group);
            }
        }
        return groups;
    }
};

int main() {
    Solution obj;
    auto run = [&](vector<string> strs)->void {
        auto ans = obj.groupAnagrams(strs);
        for (auto & vec : ans) {
            for (auto & str : vec) {
                cout << str << " ";
            }
            cout << endl;
        }
    };
    run({"eat", "tea", "tan", "ate", "nat", "bat"});
    return 0;
}
