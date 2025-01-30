// https://leetcode.com/problems/set-matrix-zeroes/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> row(n,0);
        vector<int> col(m,0);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(matrix[i][j]==0)
                {
                    row[i]=1;
                    col[j]=1;
                }
            }
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(row[i] || col[j])
                    matrix[i][j]=0;
            }   
        }
    }
};

// Approach
// 1. Create two auxiliary arrays, `row` and `col`, of size `n` and `m`, initialized with `0`.
// 2. Traverse the matrix to find all cells containing `0` and mark their corresponding row and column in `row` and `col` arrays.
// 3. Traverse the matrix again and set `matrix[i][j] = 0` if either `row[i]` or `col[j]` is marked as `1`.
// 4. This ensures that only necessary rows and columns are updated without modifying the matrix prematurely.

// Complexity Analysis
// - Time Complexity: O(n * m), since we traverse the matrix twice.
// - Space Complexity: O(n + m), due to the additional `row` and `col` arrays used for marking.