/* Given two words (beginWord and endWord), and a dictionary's word list,
 * find the length of shortest transformation sequence from beginWord to endWord, such that:
 * Only one letter can be changed at a time.
 * Each transformed word must exist in the word list.
 * Note that beginWord is not a transformed word.
 * For example,
 * Given:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log","cog"]
 * As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
 * return its length 5.
 * Note:
 * Return 0 if there is no such transformation sequence.
 * All words have the same length.
 * All words contain only lowercase alphabetic characters.
 * You may assume no duplicates in the word list.
 * You may assume beginWord and endWord are non-empty and are not the the same.
 */

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
  public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        queue<string> words;
        words.push(beginWord);
        int num_next = 1;
        int num_cur = 0;
        int length = 1;
        while (num_next > 0) {
            num_cur = num_next;
            num_next = 0;
            while (num_cur > 0) {
                string word = words.front();
                words.pop();
                -- num_cur;
                if (word == endWord) return length;
                num_next += findWords(word, dict, words);
            }
            ++ length;
        }
        return 0;
    }

    int findWords(const string& word, unordered_set<string>& dict, queue<string>& words) {
        int num = 0;
        for (uint32_t i = 0; i < word.size(); ++i) {
            string new_word = word;
            for (uint32_t k = 0; k < 26; k++) {
                new_word[i] = 'a'+k;
                if (word != new_word && dict.count(new_word)) {
                    words.push(new_word);
                    dict.erase(new_word);
                    ++ num;
                }
            }
        }
        return num;
    }
};

int main() {
    Solution obj;
    vector<string> wordList({"hot","dot","dog","lot","log","cog"});
    cout << obj.ladderLength("hit", "cog", wordList) << endl;
    return 0;
}
