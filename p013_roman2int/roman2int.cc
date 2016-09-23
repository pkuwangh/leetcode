/* Given a roman numeral, convert it to an integer.
 *
 * Input is guaranteed to be within the range from 1 to 3999.
 */

#include <iostream>
#include <string>
using namespace std;

class Solution {
  public:
    int romanToInt(string s) {
        static const int num_symbols = 7;
        char symbols[num_symbols+1] = "IVXLCDM";
        int values[num_symbols] = {1, 5, 10, 50, 100, 500, 1000};
        // build a hash table
        int map[26];
        for (int i = 0; i < num_symbols; ++i) {
            map[symbols[i]-'A'] = i;
        }
        // parse
        int num = 0;
        for (size_t i = 0; i < s.length(); ++i) {
            if (i+1 < s.length() && map[s[i]-'A'] < map[s[i+1]-'A']) {
                num -= values[ map[s[i]-'A'] ];
            } else {
                num += values[ map[s[i]-'A'] ];
            }
        }
        return num;
    }
};

int main() {
    Solution obj;

    auto run = [&](string s)->void {
        cout << s << " : " << obj.romanToInt(s) << endl;
    };

    run("IX");
    run("IV");
    run("XL");
    run("XLI");
    run("XLIX");
    run("MCMXC");

    return 0;
}
