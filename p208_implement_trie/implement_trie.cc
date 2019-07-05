/* Implement a trie with insert, search, and startsWith methods.
 * Example:
 * Trie trie = new Trie();
 * trie.insert("apple");
 * trie.search("apple");   // returns true
 * trie.search("app");     // returns false
 * trie.startsWith("app"); // returns true
 * trie.insert("app");   
 * trie.search("app");     // returns true
 * Note:
 * You may assume that all inputs are consist of lowercase letters a-z.
 * All inputs are guaranteed to be non-empty strings.
 */

#include <string>
#include <map>
#include <iostream>
using namespace std;

class Trie {
  public:
    struct TrieNode {
        TrieNode() :
            endOfWord(false)
        { }
        map<char, TrieNode*> children;
        bool endOfWord;
    };

    /** Initialize your data structure here. */
    Trie() {
        root_ = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* node = root_;
        for (unsigned i = 0; i < word.length(); ++i) {
            if (node->children.count(word[i]) > 0) {
                node = node->children[word[i]];
            } else {
                node->children[word[i]] = new TrieNode();
                node = node->children[word[i]];
            }
        }
        node->endOfWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* node = root_;
        for (unsigned i = 0; i < word.length(); ++i) {
            if (node->children.count(word[i]) > 0) {
                node = node->children[word[i]];
            } else {
                return false;
            }
        }
        return node->endOfWord;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* node = root_;
        for (unsigned i = 0; i < prefix.length(); ++i) {
            if (node->children.count(prefix[i]) > 0) {
                node = node->children[prefix[i]];
            } else {
                return false;
            }
        }
        return true;
    }

  private:
    TrieNode* root_ = nullptr;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main() {
    Trie* obj = new Trie();
    obj->insert("apple");
    cout << obj->search("apple") << endl;
    cout << obj->search("app") << endl;
    cout << obj->startsWith("app") << endl;
    obj->insert("app");
    cout << obj->search("app") << endl;
    return 0;
}

