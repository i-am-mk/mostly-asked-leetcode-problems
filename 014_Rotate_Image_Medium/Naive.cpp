// https://leetcode.com/problems/rotate-image/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> ans(n, (vector<int>(n)));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
                ans[j][n-i-1]=matrix[i][j];
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
                matrix[i][j]=ans[i][j];
        }
    }
};

// Approach
// 1. The problem requires rotating a square matrix by 90 degrees clockwise.
// 2. To achieve this, we can first construct a new matrix `ans` where we place elements
//    in their correct rotated positions.
// 3. The element at position `matrix[i][j]` will move to `ans[j][n-i-1]`.
// 4. After constructing the rotated matrix, we copy the contents of `ans` back into `matrix`.

// Complexity Analysis
// - Time Complexity: O(n * m), where n is the number of rows and m is the number of columns.
//   Each element in the matrix is visited twice: once for placing in `ans` and once for copying it back.
// - Space Complexity: O(n * m), because we are using an additional matrix `ans` of the same size as `matrix`.