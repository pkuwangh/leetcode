/* Given two words (beginWord and endWord), and a dictionary's word list,
 * find all shortest transformation sequence(s) from beginWord to endWord, such that:
 * Only one letter can be changed at a time
 * Each transformed word must exist in the word list.
 * Note that beginWord is not a transformed word.
 * For example,
 * Given:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log","cog"]
 * Return
 *   [
 *     ["hit","hot","dot","dog","cog"],
 *     ["hit","hot","lot","log","cog"]
 *   ]
 * Note:
 * Return an empty list if there is no such transformation sequence.
 * All words have the same length.
 * All words contain only lowercase alphabetic characters.
 * You may assume no duplicates in the word list.
 * You may assume beginWord and endWord are non-empty and are not the same.
 */

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>  // hash table
using namespace std;

class Solution {
  public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList)
    {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        // step 1: BFS to find minimum length
        int min_length = BFS(beginWord, endWord, dict);
        // step 2: DFS to find path
        vector<vector<string>> all_sols;
        vector<string> sol;
        int length = 1;
        sol.push_back(beginWord);
        DFS(all_sols, sol, length, min_length, endWord, dict);
        return all_sols;
    }

    void DFS(vector<vector<string>>& all_sols, vector<string>& sol, int& length,
             const int& min_length, const string& endWord, unordered_set<string> &dict)
    {
        const string& beginWord = sol.back();
        if (beginWord == endWord) {
            all_sols.push_back(sol);
            return;
        }
        if (length >= min_length) {
            // not a min-length solution
            return;
        }
        // DFS
        queue<string> word_queue;
        queue<string> back_queue;
        findWords(beginWord, dict, word_queue);
        while (!word_queue.empty()) {
            auto word = word_queue.front();
            word_queue.pop();
            back_queue.push(word);
            sol.push_back(word);
            ++ length;
            DFS(all_sols, sol, length, min_length, endWord, dict);
            sol.pop_back();
            -- length;
        }
        while (!back_queue.empty()) {
            dict.insert(back_queue.front());
            back_queue.pop();
        }
    }

    int BFS(const string& beginWord, const string& endWord, unordered_set<string> dict)
    {
        queue<string> word_queue;
        // level-order BFS
        word_queue.push(beginWord);
        int num_next = 1;
        int num_cur = 0;
        int length = 1;
        while (num_next > 0) {
            num_cur = num_next;
            num_next = 0;
            while (num_cur > 0) {
                string word = word_queue.front();
                word_queue.pop();
                -- num_cur;
                if (word == endWord) return length;
                num_next += findWords(word, dict, word_queue);
            }
            ++ length;
        }
        return 0;
    }

    int findWords(const string& word, unordered_set<string>& dict, queue<string>& words) {
        int num = 0;
        for (uint32_t i = 0; i < word.size(); ++i) {
            string new_word = word;
            for (uint32_t k = 0; k < 26; ++k) {
                new_word[i] = 'a' + k;
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
    auto ans = obj.findLadders("hit", "cog", wordList);
    for (auto &path : ans) {
        for (auto &word : path) {
            cout << word << " ";
        }
        cout << endl;
    }
    return 0;
}
