// https://leetcode.com/problems/set-matrix-zeroes/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int col0 = 1;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(matrix[i][j]==0)
                {
                    matrix[i][0]=0;
                    if(j==0)
                        col0=0;
                    else
                        matrix[0][j]=0;
                }
            }
        }
        for(int i=1; i<n; i++)
        {
            for(int j=1; j<m; j++)
            {
                if(matrix[i][j]!=0)
                {
                    if(matrix[i][0]==0 || matrix[0][j]==0)
                        matrix[i][j]=0;
                }
            }
        }

        if(matrix[0][0]==0)
        {
            for(int j=0; j<m; j++)
                matrix[0][j]=0;
        }

        if(col0==0)
        {
            for(int i=0; i<n; i++)
                matrix[i][0]=0;
        }
    }
};

// Approach
// 1. We use the first row and the first column to mark which rows and columns 
//    need to be set to zero. A variable `col0` is used to track if the first column 
//    needs to be zeroed.
// 2. Traverse the matrix to find all elements that are zero. For each zero, mark the 
//    corresponding row and column in the first row and the first column.
// 3. Traverse the matrix again, and for each element, set it to zero if the corresponding 
//    row or column is marked in the first row or column.
// 4. Finally, handle the special cases of the first row and the first column separately 
//    since they are used as markers.

// Complexity Analysis
// - Time Complexity: O(n * m), where n is the number of rows and m is the number of columns. 
//   We traverse the matrix multiple times, but the operations are constant-time for each element.
// - Space Complexity: O(1), since no extra space is used apart from the input matrix. Only a constant variable `col0` is used.