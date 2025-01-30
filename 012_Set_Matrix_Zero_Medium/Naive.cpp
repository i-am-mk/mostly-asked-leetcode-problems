// https://leetcode.com/problems/set-matrix-zeroes/
class Solution {
public:
    void markRow(vector<vector<int>> &matrix, int i, int m)
    {
        for(int j=0; j<m; j++)
        {
            if(matrix[i][j]!=0)
                matrix[i][j]=-1;
        }   
    }

    void markCol(vector<vector<int>> &matrix, int j, int n)
    {
        for(int i=0; i<n; i++)
        {
            if(matrix[i][j]!=0)
                matrix[i][j]=-1;
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(matrix[i][j]==0)
                {
                    markRow(matrix, i, m);
                    markCol(matrix, j, n);
                }
            }
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(matrix[i][j]==-1)
                    matrix[i][j]=0;
            }   
        }
    }
};

// Approach
// 1. Traverse the matrix to find all the cells containing `0`.
// 2. Whenever a `0` is found at position `(i, j)`, mark the entire row `i` and column `j` by setting all non-zero elements to `-1` (as a placeholder).
// 3. After the marking phase, traverse the matrix again and replace all `-1` values with `0`.
// 4. This ensures that only the required rows and columns are set to `0` without affecting other elements during traversal.

// Complexity Analysis
// - Time Complexity: O(n * m), since we traverse the matrix multiple times.
// - Space Complexity: O(1), since we modify the matrix in place without using extra space.