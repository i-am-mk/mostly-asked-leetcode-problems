// https://leetcode.com/problems/word-search-ii/ Time Limit Exceeded
struct Node
{
    Node* links[26];
    bool flag = false;

    bool containsKey(char ch)
    {
        return ch >= 'a' && ch <= 'z' && links[ch - 'a'] != nullptr;
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

class Solution {
private:
    Node* root;
    vector<vector<int>> dir = { {-1, 0}, {1, 0}, {0, -1}, {0,1} };
    
    void dfs(vector<vector<char>>& board, int i, int j, string word, Node* root, unordered_set<string> &st)
    {
        if(board[i][j]=='#')
            return;

        char temp = board[i][j];
        word.push_back(temp);
        if(root->isEnd())
        {
            st.insert(word);
            root->setEnd();
        }
        board[i][j]='#';
        for(auto d: dir)
        {
            int newi = i+d[0];
            int newy = j+d[1];
            if(newi>=0 && newi<board.size() && newy>=0 && newy<board[i].size() && root->containsKey(board[newi][newy]))
            {
                dfs(board, newi, newy, word, root->get(board[newi][newy]), st);
            }
        }

        board[i][j]=temp;
    }

public:
    Solution()
    {
        root = new Node();
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        if(board.empty() || words.empty())
            return ans;

        for(int i=0; i<words.size(); i++)
        {
            Node* node = root;
            for(int j=0; j<words[i].length(); j++)
            {
                if(!node->containsKey(words[i][j]))
                    node->put(words[i][j], new Node());
                node = node->get(words[i][j]);

                if(j==words[i].length()-1)
                    node->setEnd();
            }
        }

        unordered_set<string> st;
        for(int i=0; i<board.size(); i++)
        {
            for(int j=0; j<board[0].size(); j++)
            {
                if(root->containsKey(board[i][j]))
                {
                    string word = "";
                    dfs(board, i, j, word, root->get(board[i][j]), st);
                }
            }
        }
        ans.assign(st.begin(), st.end());
        return ans;
    }
};

// Approach:
// 1. Trie Construction: 
//    - Insert all the words into a Trie. Each node represents a character, and we store the word at the end of a word node.
//    - Trie is built such that each node contains links for all the alphabet letters 'a' to 'z', which helps us traverse the board and check whether a word exists.
  
// 2. DFS + Backtracking:
//    - Traverse the board, and for each character, use DFS to explore potential words in all 4 possible directions (up, down, left, right).
//    - If a character matches a valid Trie node, continue the DFS, forming a word along the way.
//    - If a valid word is found (i.e., node's end flag is set), store the word in the result set and mark it to avoid duplicate results.
//    - Use a visited mechanism (replace board cells with '#') to avoid revisiting the same cell during a single DFS traversal.
//    - After DFS completion for a cell, backtrack by restoring the board to its original state.

// 3. Trie Pruning:
//    - After each DFS search, prune the Trie to remove unused nodes (i.e., if a node has no further children, delete it to save memory and avoid redundant searches).

// Complexity Analysis:
// 1. Trie Construction: 
//    - Time Complexity: O(W * L) where W is the number of words and L is the average length of words in the dictionary.
//    - Space Complexity: O(W * L) for storing the Trie, which contains each word's characters as nodes.

// 2. DFS Traversal:
//    - Time Complexity: O(m * n * 4^L), where m is the number of rows, n is the number of columns, and L is the maximum length of any word. In the worst case, we explore all directions at each step, forming all possible words from each cell.
//    - Space Complexity: O(L) for the recursion stack during DFS traversal (where L is the max length of words in the board).

// 3. Overall Complexity:
//    - Time Complexity: O(W * L + m * n * 4^L), where the first part is the time for Trie construction and the second part is the time for the DFS traversal.
//    - Space Complexity: O(W * L + m * n), accounting for the Trie storage and the board storage.