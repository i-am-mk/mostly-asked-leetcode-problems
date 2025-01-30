// https://leetcode.com/problems/word-search/
class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word, int i, int j, int count)
    {
        if(count==word.size())
            return true;
        
        if(i>=board.size() || i<0 || j>=board[0].size() || j<0 || board[i][j]!=word[count])
            return false;
        
        char temp = board[i][j];
        board[i][j] = '*';

        bool left = dfs(board,word,i,j-1,count+1);
        bool right = dfs(board,word,i,j+1, count+1);
        bool top = dfs(board,word,i-1,j,count+1); 
        bool bottom = dfs(board,word,i+1,j,count+1);
        bool found = left || right || top || bottom;

        board[i][j] = temp;
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(board[i][j] == word[0] && dfs(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }
};

// Approach
// 1. We need to find whether a given word can be formed in a 2D board by moving horizontally or vertically from one cell to the next.
// 2. We use Depth First Search (DFS) to explore all possible paths starting from each cell that matches the first character of the word.
//    - Starting from each cell, we attempt to form the word by checking all four directions (left, right, top, bottom).
// 3. For each cell, we check if it matches the character at the current position in the word. If it does, we mark it as visited (by replacing the character with a special symbol, e.g., '*'), and recursively check the next characters in all four directions.
// 4. If we successfully find the entire word, we return `true`. If not, we backtrack by restoring the character to its original value and continue searching from the next cell.
// 5. We repeat this process for all cells in the board until we either find the word or exhaust all possibilities.

// Complexity Analysis
// - Time Complexity: O(m * n * 4^L), where m is the number of rows, n is the number of columns, and L is the length of the word.
//   - For each cell (m * n), we explore up to 4 possible directions recursively. In the worst case, we explore all paths up to the length of the word.
// - Space Complexity: O(L), where L is the length of the word. 
//   - This is due to the recursion stack that can go as deep as the length of the word.
