/* All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG".
 * When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.
 *
 * Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.
 * Example:
 * Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
 * Output: ["AAAAACCCCC", "CCCCCAAAAA"]
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
  public:
    int encode(const char& c) const {
        if (c == 'A') return 0;
        else if (c == 'C') return 1;
        else if (c == 'G') return 2;
        else  return 3;
    }

    string decode(unsigned num) const {
        string s(10, 'A');
        for (int i = 0; i < 10; ++i) {
            int c = num % 4;
            if (c == 0) s[9-i] = 'A';
            else if (c == 1) s[9-i] = 'C';
            else if (c == 2) s[9-i] = 'G';
            else s[9-i] = 'T';
            num /= 4;
        }
        return s;
    }

    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> sol;
        if (s.length() <= 10) return sol;
        unordered_map<int, int> dict;
        const unsigned mask = ((unsigned)1 << 20) - 1;
        unsigned num = 0;
        for (unsigned i = 0; i < s.length(); ++i) {
            num = ((num << 2) + encode(s[i])) & mask;
            if (i >= 9) {
                // check if there is a match
                if (dict.count(num) > 0) {
                    if (dict[num] == 1) {
                        // find a repeated pattern
                        sol.emplace_back(decode(num));
                    }
                    dict[num] += 1;
                } else {
                    // add to dict
                    dict[num] = 1;
                }
            }
        }
        return sol;
    }
};

int main() {
    Solution obj;
//    vector<string> res = obj.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
    vector<string> res = obj.findRepeatedDnaSequences("AAAAAAAAAAA");
    for (auto& s : res) {
        cout << s << endl;
    }
    return 0;
}
