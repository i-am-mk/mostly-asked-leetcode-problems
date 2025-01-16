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