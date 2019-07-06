/* Given a 2D board and a list of words from the dictionary, find all words in the board.
 * Each word must be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring.
 * The same letter cell may not be used more than once in a word.
 * Example:
 * Input: 
 * board = [
 *   ['o','a','a','n'],
 *   ['e','t','a','e'],
 *   ['i','h','k','r'],
 *   ['i','f','l','v']
 *  ]
 * words = ["oath","pea","eat","rain"]
 * Output: ["eat","oath"]
 * Note:
 * All inputs are consist of lowercase letters a-z.
 * The values of words are distinct.
 */

#include <vector>
#include <string>
#include <map>
#include <iostream>
using namespace std;

class Solution {
  public:
    struct TrieNode {
        TrieNode() :
            end_of_word (false)
        { }
        bool end_of_word;
        map<char, TrieNode*> children;
    };

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // build a trie
        TrieNode* root = new TrieNode();
        for (const auto& word : words) {
            TrieNode* node = root;
            for (unsigned i = 0; i < word.length(); ++i) {
                if (node->children.count(word[i]) == 0) {
                    node->children[word[i]] = new TrieNode();
                }
                node = node->children[word[i]];
            }
            node->end_of_word = true;
        }
        // dfs
        vector<string> all_sols;
        for (unsigned i = 0; i < board.size(); ++i) {
            for (unsigned j = 0; j < board[i].size(); ++j) {
                // try each position as starting point
                vector<vector<bool>> visited(board.size(), vector<bool>(board[i].size(), false));
                string sol;
                dfs(board, i, j, visited, root, sol, all_sols);
            }
        }
        return all_sols;
    }

    void dfs(vector<vector<char>>& board, unsigned row, unsigned col,
            vector<vector<bool>>& visited, TrieNode* root, string& sol, vector<string>& all_sols) {
        if (visited[row][col]) {
            // a cell not used twice
            return;
        }
        if (root->children.count(board[row][col]) == 0) {
            // not in dict
            return;
        }
        TrieNode* node = root->children[board[row][col]];
        // take this cell
        visited[row][col] = true;
        sol.push_back(board[row][col]);
        if (node->end_of_word) {
            // find one valid word
            all_sols.push_back(sol);
            // de-duplicate
            node->end_of_word = false;
        }
        // try 4 directions
        if (row > 0) {
            dfs(board, row-1, col, visited, node, sol, all_sols);
        }
        if (col > 0) {
            dfs(board, row, col-1, visited, node, sol, all_sols);
        }
        if (row < board.size()-1) {
            dfs(board, row+1, col, visited, node, sol, all_sols);
        }
        if (col < board[row].size()-1) {
            dfs(board, row, col+1, visited, node, sol, all_sols);
        }
        // roll back
        visited[row][col] = false;
        sol.pop_back();
    }
};

int main() {
    Solution obj;
    auto run = [&](vector<vector<char>> board, vector<string> words)->void {
        for (auto& row : board) {
            for (auto& c : row) {
                cout << c << " ";
            }
            cout << endl;
        }
        cout << "words: ";
        for (auto& w : words) {
            cout << w << " ";
        }
        cout << endl << "ans: ";
        auto ans = obj.findWords(board, words);
        for (auto& x : ans) {
            cout << x << " ";
        }
        cout << endl;
    };
    run({{'o','a','a','n'}, {'e','t','a','e'}, {'i','h','k','r'}, {'i','f','l','v'}}, {"oath","pea","eat","rain"});
    run({{'a','a'}}, {"a"});
    return 0;
}
