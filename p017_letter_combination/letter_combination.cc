/* Given a digit string, return all possible letter combinations
 * that the number could represent.
 * A mapping of digit to letters is just like on the telephone buttons.
 *
 * Input:Digit string "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
  public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        string letters(digits.size(), 0);
        vector<string> letter_map =
        {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        if (letters.size() > 0) {
            translate(result, letters, letter_map, digits, 0);
        }
        return result;
    }

    void translate(vector<string>& result, string& letters,
                   const vector<string>& letter_map, const string& digits, int k)
    {
        if (k == (int)digits.size()) {
            // finished one letter combination
            result.push_back(letters);
            return;
        }
        // pick the letter at kth position
        int num = (int)(digits[k] - '0');
        string str = letter_map.at(num);
        int len = str.size();
        for (int i = 0; i < len; ++i) {
            letters[k] = str[i];
            // pick next letter at k+1th position
            translate(result, letters, letter_map, digits, k+1);
        }
    }
};

int main()
{
    Solution obj;
    auto words = obj.letterCombinations("23");
    for (auto & s : words) {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}
