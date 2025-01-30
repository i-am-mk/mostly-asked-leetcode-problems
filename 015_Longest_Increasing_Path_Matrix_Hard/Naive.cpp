// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty())
            return 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        int longestPath = 0;
        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<cols; j++)
                longestPath = max(longestPath, dfs(matrix, rows, cols, i, j, dp));
        }
        return longestPath;
    }

private:
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int dfs(vector<vector<int>> &matrix, int rows, int cols, int x, int y, vector<vector<int>> &dp)
    {
        if(dp[x][y]!=0)
            return dp[x][y];
        int maxLength = 1;
        for(auto dir: directions)
        {
            int newx = x + dir.first;
            int newy = y + dir.second;
            if(newx>=0 && newx<rows && newy>=0 && newy<cols && matrix[newx][newy]>matrix[x][y])
            {
                int len = 1 + dfs(matrix, rows, cols, newx, newy, dp);
                maxLength = max(maxLength, len);
            }
        }
        dp[x][y]=maxLength;
        return maxLength;
    }
};

// Approach
// 1. We need to find the longest strictly increasing path in a matrix.
// 2. We use dynamic programming (DP) to store the result of subproblems and avoid redundant calculations.
//    - Define `dp[i][j]` to represent the longest increasing path starting from matrix[i][j].
// 3. For each cell in the matrix, we perform a Depth First Search (DFS) to explore all possible paths starting from that cell.
//    - At each step, we try to move in all four possible directions (up, down, left, right) if the next cell has a greater value than the current cell.
//    - We store the maximum path length for each cell in the `dp` array.
// 4. We initialize `longestPath` to 0, and as we explore each cell, we update it with the longest increasing path found.

// Complexity Analysis
// - Time Complexity: O(m * n), where m is the number of rows and n is the number of columns. 
//   - Each cell is visited once, and the DFS function is called at most once for each cell. 
//     The recursion has at most 4 directions to explore, but each direction will be computed only once for each cell.
// - Space Complexity: O(m * n), where m is the number of rows and n is the number of columns. 
//   - We use a DP table (`dp`) of size m * n to store the longest path from each cell. The recursion stack will also take up to O(m * n) space in the worst case.
