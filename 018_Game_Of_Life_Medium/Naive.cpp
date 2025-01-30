// https://leetcode.com/problems/game-of-life/
class Solution {
public:
    int getLiveNeighbours(vector<vector<int>> copy, int n, int m, int i, int j)
    {
        int len=0;
        // Top
        if(i>0 && copy[i-1][j]==1)
            len++;

        // Bottom
        if(i<n-1 && copy[i+1][j]==1)
            len++;

        // Left
        if(j>0 && copy[i][j-1]==1)
            len++;

        // Right
        if(j<m-1 && copy[i][j+1]==1)
            len++;

        // Top Left
        if(i>0 && j>0 && copy[i-1][j-1]==1)
            len++;

        // Top Right
        if(i>0 && j<m-1 && copy[i-1][j+1]==1)
            len++;

        // Bottom Left
        if(i<n-1 && j>0 && copy[i+1][j-1]==1)
            len++;

        // Bottom Right
        if(i<n-1 && j<m-1 && copy[i+1][j+1]==1)
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
                        board[i][j]=1;
                }
                if(board[i][j]==1)
                {
                    if(len<2 || len>3)
                        board[i][j]=0;
                }
            }
        }
    }
};

// Approach
// 1. The Game of Life involves updating the board based on the current state of cells, where:
//    - A live cell with fewer than 2 live neighbours dies (under-population).
//    - A live cell with more than 3 live neighbours dies (over-population).
//    - A dead cell with exactly 3 live neighbours becomes alive (reproduction).
//    - All other live cells remain alive and all other dead cells remain dead.
// 2. We iterate over each cell in the grid and count its live neighbours using the `getLiveNeighbours` function. 
//    This function checks all 8 possible directions around the cell (top, bottom, left, right, and the 4 diagonals).
// 3. Based on the number of live neighbours, we update the board accordingly:
//    - If the cell is dead and has exactly 3 live neighbours, it becomes live.
//    - If the cell is live and has fewer than 2 or more than 3 live neighbours, it dies.

// Complexity Analysis
// Time Complexity:
// - The time complexity is O(n * m), where n is the number of rows and m is the number of columns in the board. 
//   We iterate over each cell once and check its 8 possible neighbours, which is constant time for each cell.
// Space Complexity:
// - The space complexity is O(n * m) for storing a copy of the board to count live neighbours, which is required to prevent modifying the board while evaluating its new state.