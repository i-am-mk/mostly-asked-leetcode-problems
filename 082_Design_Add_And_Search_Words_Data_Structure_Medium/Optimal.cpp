// https://leetcode.com/problems/design-add-and-search-words-data-structure/
struct Node
{
    Node* links[26];
    bool flag = false;

    bool containsKey(char ch)
    {
        return links[ch-'a'];
    }

    void put(char ch, Node* node)
    {
        links[ch-'a'] = node;
    }

    Node* get(char ch)
    {
        return links[ch-'a'];
    }

    void setEnd()
    {
        flag = true;
    }

    bool isEnd()
    {
        return flag;
    }
};

class WordDictionary {
private:
    Node* root;
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* node = root;
        for(int i=0; i<word.length(); i++)
        {
            if(!node->containsKey(word[i]))
                node->put(word[i], new Node());
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        return searchHelper(word, 0, root);
    }

    bool searchHelper(string word, int index, Node* node)
    {
        if(word.length()==index)
            return node->isEnd();
        char ch = word[index];
        if(ch=='.')
        {
            for(int i=0; i<26; i++)
            {
                if(node->links[i] && searchHelper(word, index+1, node->links[i]))
                    return true;
            }
            return false;
        }
        else
        {
            if(!node->containsKey(ch))
                return false;
            return searchHelper(word, index+1, node->get(ch));
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

/*
Approach:
1. Trie (Prefix Tree) Implementation:
   - Each `Node` stores an array of 26 pointers (one for each lowercase letter).
   - `flag` is used to mark the end of a word.
   - The `addWord` function inserts words into the Trie.
   - The `search` function supports exact word matching and wildcard (`.`) matching.

2. Insertion (`addWord`):
   - Start from the root node.
   - For each character in the word:
     - If the character is not present, create a new node.
     - Move to the next node.
   - Mark the last node as the end of a word.

3. Search with Wildcard (`search`):
   - If the character is a letter, follow the Trie path.
   - If the character is `.`, recursively try all 26 possible paths.
   - If the word ends, return `true` only if the last node marks the end of a word.

Time Complexity:
1. Insertion (`addWord`): O(n), where `n` is the length of the word.
2. Search (`search`):
   - Best case (exact match): O(n).
   - Worst case (wildcard `.` at every position): O(26^m), where `m` is the number of `.` characters in the word.
*/