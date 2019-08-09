/**
 * Given a string array words, find the maximum value of length(word[i]) * length(word[j])
 * where the two words do not share common letters. You may assume that each word will
 * contain only lower case letters. If no such two words exist, return 0.
 * Example 1:
 * Input: ["abcw","baz","foo","bar","xtfn","abcdef"]
 * Output: 16 
 * Explanation: The two words can be "abcw", "xtfn".
 * Example 2:
 * Input: ["a","ab","abc","d","cd","bcd","abcd"]
 * Output: 4 
 * Explanation: The two words can be "ab", "cd".
 * Example 3:
 * Input: ["a","aa","aaa","aaaa"]
 * Output: 0 
 * Explanation: No such pair of words.
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
using namespace std;

class Solution {
  public:
    int maxProduct(vector<string>& words) {
        if (words.size() == 0) return 0;
        vector<uint32_t> dicts(words.size(), 0);
        for (int i = 0; i < words.size(); ++i) {
            for (auto& c : words[i]) {
                dicts[i] |= (uint32_t)(1) << (c - 'a');
            }
        }
        int max_product = 0;
        for (int i = 0; i < words.size(); ++i) {
            for (int j = i+1; j < words.size(); ++j) {
                if ((dicts[i] & dicts[j]) == 0) {
                    const int product = words[i].length() * words[j].length();
                    max_product = max(product, max_product);
                }
            }
        }
        return max_product;
    }
};

int main() {
    Solution obj;
    auto run = [&](vector<string> words) ->void {
        cout << obj.maxProduct(words) << endl;
    };
    run({"abcw","baz","foo","bar","xtfn","abcdef"});
    run({"a","ab","abc","d","cd","bcd","abcd"});
    run({"a","aa","aaa","aaaa"});
    return 0;
}
