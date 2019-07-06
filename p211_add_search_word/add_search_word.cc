/* Design a data structure that supports the following two operations:
 *    void addWord(word)
 *    bool search(word)
 *    search(word) can search a literal word or a regular expression string containing only letters a-z or ..
 *    A . means it can represent any one letter.
 * Example:
 * addWord("bad")
 * addWord("dad")
 * addWord("mad")
 * search("pad") -> false
 * search("bad") -> true
 * search(".ad") -> true
 * search("b..") -> true
 * Note:
 * You may assume that all words are consist of lowercase letters a-z.
 */

#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

class WordDictionary {
  public:
    // use a trie as base structure
    struct TrieNode {
        TrieNode() :
            end_of_word(false)
        { }
        map<char, TrieNode*> children;
        bool end_of_word;
    };

    /** Initialize your data structure here. */
    WordDictionary() {
        root_ = new TrieNode();
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* node = root_;
        for (unsigned i = 0; i < word.length(); ++i) {
            if (node->children.count(word[i]) == 0) {
                node->children[word[i]] = new TrieNode();
            }
            node = node->children[word[i]];
        }
        node->end_of_word = true;
    }

    /**
     * Returns if the word is in the data structure.
     * A word could contain the dot character '.' to represent any one letter.
     */
    bool search(string word) {
        return dfs(word, 0, root_);
    }

    bool dfs(string word, unsigned n, TrieNode* root) {
        // check end-of-word
        if (word.length() == n) {
            return root->end_of_word;
        }
        // recursive call
        if (word[n] == '.') {
            for (const auto& item : root->children) {
                if (dfs(word, n+1, item.second)) {
                    return true;
                }
            }
            return false;
        } else if (root->children.count(word[n]) > 0) {
            return dfs(word, n+1, root->children[word[n]]);
        } else {
            return false;
        }
    }

  private:
    TrieNode* root_ = nullptr;
};

int main() {
    WordDictionary* obj = new WordDictionary();
    obj->addWord("bad");
    obj->addWord("dad");
    obj->addWord("mad");
    cout << obj->search("pad") << endl;
    cout << obj->search("bad") << endl;
    cout << obj->search("ba") << endl;
    cout << obj->search(".ad") << endl;
    cout << obj->search("b..") << endl;
    return 0;
}

