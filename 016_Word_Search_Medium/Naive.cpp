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
