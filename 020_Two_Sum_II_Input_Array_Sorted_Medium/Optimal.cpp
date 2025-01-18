// https://leetcode.com/problems/game-of-life/
class Solution {
public:
    int getLiveNeighbours(vector<vector<int>> copy, int n, int m, int i, int j)
    {
        int len=0;
        // Top
        if(i>0 && (copy[i-1][j]==1 || copy[i-1][j]==3))
            len++;

        // Bottom
        if(i<n-1 && (copy[i+1][j]==1 || copy[i+1][j]==3))
            len++;

        // Left
        if(j>0 && (copy[i][j-1]==1 || copy[i][j-1]==3))
            len++;

        // Right
        if(j<m-1 && (copy[i][j+1]==1 || copy[i][j+1]==3))
            len++;

        // Top Left
        if(i>0 && j>0 && (copy[i-1][j-1]==1 || copy[i-1][j-1]==3))
            len++;

        // Top Right
        if(i>0 && j<m-1 && (copy[i-1][j+1]==1 || copy[i-1][j+1]==3))
            len++;

        // Bottom Left
        if(i<n-1 && j>0 && (copy[i+1][j-1]==1 || copy[i+1][j-1]==3))
            len++;

        // Bottom Right
        if(i<n-1 && j<m-1 && (copy[i+1][j+1]==1 || copy[i+1][j+1]==3))
            len++;

        return len;
    }

    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> copy = board;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                int len = getLiveNeighbours(copy, n, m, i, j);
                if(board[i][j]==0)
                {
                    if(len==3)
                        board[i][j]=2;
                }
                if(board[i][j]==1)
                {
                    if(len<2 || len>3)
                        board[i][j]=3;
                }
            }
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(board[i][j]==2)
                    board[i][j]=1;
                if(board[i][j]==3)
                    board[i][j]=0;
            }
        }
    }
};