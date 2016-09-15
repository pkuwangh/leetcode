/* Given a string S, find the longest palindromic substring in S.
 * You may assume that the maximum length of S is 1000,
 * and there exists one unique longest palindromic substring.
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

/* analysis
 * abcxyxtq
 * a != q, abcxyxt vs. bcxyxtq
 */

class Solution {
  public:
    // dynamic programming, O(n^2)
    // p[i, j] tells if string s[i : j] is palindromic
    // p[i : j] = p[i+1 : j-1] && s[i] == s[j]
    string longestPalindrome(string s) {
        bool p[1000][1000] = {false};
        int size = s.length();
        // initialize p[n][n] as true
        for (int i = 0; i < size; ++i) {
            p[i][i] = true;
        }
        int start = 0;
        int max_length = 1;
        // calculate p[n][n+1]
        for (int i = 0; i < size - 1; ++i) {
            if (s[i] == s[i+1]) {
                p[i][i+1] = true;
                start = i;
                max_length = 2;
            }
        }
        // expand to p[n][n+l]
        for (int l = 3; l <= size; ++l) {
            for (int i = 0; (i+l-1) < size; ++i) {
                if (p[i+1][i+l-2] && (s[i] == s[i+l-1])) {
                    p[i][i+l-1] = true;
                    if (max_length < l) {
                        start = i;
                        max_length = l;
                    }
                }
            }
        }
        return s.substr(start, max_length);
    }

#if 0
    // simply using recursion effectively enumerates all substrings, O(n^2)
    // then checking each substring take O(n), so overall time complexity is O(n^3)
    string longestPalindrome(string s) {
        return getLongestPalindrome(s, 0, s.length());
    }

    string getLongestPalindrome(string s, int start, int length) {
        if (isPalindrome(s, start, length)) {
            return s.substr(start, length);
        }
        string s1 = getLongestPalindrome(s, start, length - 1);
        string s2 = getLongestPalindrome(s, start + 1, length);
        if (s1.length() > s2.length()) {
            return s1;
        } else {
            return s2;
        }
    }

    bool isPalindrome(string s, int start, int length) {
        int last = start + length - 1;
        while (start < last) {
            if (s[start] != s[last]) { return false; }
            ++ start; -- last;
        }
        return true;
    }
#endif
};

int main()
{
    Solution obj;

    cout << obj.longestPalindrome("abcba") << endl;
    cout << obj.longestPalindrome("abccba") << endl;
    cout << obj.longestPalindrome("xabcbamk") << endl;
    cout << obj.longestPalindrome("abb") << endl;
    cout << obj.longestPalindrome("whdqcudjpisufnrtsyupwtnnbsvfptrcgvobbjglmpynebblpigaflpbezjvjgbmofejyjssdhbgghgrhzuplbeptpaecfdanhlylgusptlgobkqnulxvnwuzwauewcplnvcwowmbxxnhsdmgxtvbfgnuqdpxennqglgmspbagvmjcmzmbsuacxlqfxjggrwsnbblnnwisvmpwwhomyjylbtedzrptejjsaiqzprnadkjxeqfdpkddmbzokkegtypxaafodjdwirynzurzkjzrkufsokhcdkajwmqvhcbzcnysrbsfxhfvtodqabvbuosxtonbpmgoemcgkudandrioncjigbyizekiakmrfjvezuzddjxqyevyenuebfwugqelxwpirsoyixowcmtgosuggrkdciehktojageynqkazsqxraimeopcsjxcdtzhlbvtlvzytgblwkmbfwmggrkpioeofkrmfdgfwknrbaimhefpzckrzwdvddhdqujffwvtvfyjlimkljrsnnhudyejcrtrwvtsbkxaplchgbikscfcbhovlepdojmqybzhbiionyjxqsmquehkhzdiawfxunguhqhkxqdiiwsbuhosebxrpcstpklukjcsnnzpbylzaoyrmyjatuovmaqiwfdfwyhugbeehdzeozdrvcvghekusiahfxhlzclhbegdnvkzeoafodnqbtanfwixjzirnoaiqamjgkcapeopbzbgtxsjhqurbpbuduqjziznblrhxbydxsmtjdfeepntijqpkuwmqezkhnkwbvwgnkxmkyhlbfuwaslmjzlhocsgtoujabbexvxweigplmlewumcone") << endl;

    return 0;
}
