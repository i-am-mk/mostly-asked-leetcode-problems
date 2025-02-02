                            
#include <iostream>
using namespace std;

// Node structure for Trie
struct Node {
    // Array to store links to child nodes, each index represents a letter
    Node* links[26];

    // Flag indicating if the node marks the end of a word
    bool flag = false;

    // Check if the node contains a specific key (letter)
    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }

    // Insert a new node with a specific key (letter) into the Trie
    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    // Get the node with a specific key (letter) from the Trie
    Node* get(char ch) {
        return links[ch - 'a'];
    }

    // Set the current node as the end of a word
    void setEnd() {
        flag = true;
    }

    // Check if the current node marks the end of a word
    bool isEnd() {
        return flag;
    }
};

// Trie class
class Trie {
private:
    Node* root;

public:
    // Constructor to initialize the Trie with an empty root node
    Trie() {
        root = new Node();
    }

    // Inserts a word into the Trie
    void insert(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containsKey(word[i])) {
                // Create a new node for the letter if not present
                node->put(word[i], new Node());
            }
            // Move to the next node
            node = node->get(word[i]);
        }
        // Mark the end of the word
        node->setEnd();
    }

    bool search(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containsKey(word[i]))
                return false;
            node = node->get(word[i]);
        }
        // Check if the last node marks the end of a word
        return node->isEnd();
    }

    // Returns if there is any word in the trie that starts with the given prefix
    bool startsWith(string prefix) {
        Node* node = root;
        for (int i = 0; i < prefix.length(); i++) {
            if (!node->containsKey(prefix[i]))
                return false;
            node = node->get(prefix[i]);
        }
        return true;
    }
};

/*
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

 /*
 * Approach:
 * - The Trie is implemented using a tree structure where each node has 26 possible children (one for each lowercase English letter).
 * - The `insert` function traverses the Trie, adding nodes for new letters and marking the end of words.
 * - The `search` function checks whether a given word exists in the Trie by traversing the tree.
 * - The `startsWith` function checks whether any stored word starts with a given prefix.
 * 
 * Complexity Analysis:
 * - Insert Operation: O(n), where n is the length of the word.
 * - Search Operation: O(n), where n is the length of the word.
 * - Prefix Search (startsWith): O(n), where n is the length of the prefix.
 * - Space Complexity: O(N * M), where N is the number of words inserted and M is the average word length.
 */ 