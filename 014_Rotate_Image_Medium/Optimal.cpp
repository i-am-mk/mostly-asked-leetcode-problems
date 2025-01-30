// https://leetcode.com/problems/rotate-image/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<m; j++)
                swap(matrix[i][j], matrix[j][i]);
        }
        for(int i=0; i<n; i++)
            reverse(matrix[i].begin(), matrix[i].end());
    }
};

// Approach
// 1. The problem requires rotating a square matrix by 90 degrees clockwise.
// 2. To rotate the matrix, we perform two steps:
//    - Transpose the matrix: This means we swap elements matrix[i][j] with matrix[j][i] for all i, j.
//    - Reverse each row: After transposing, we reverse the elements of each row to get the final rotated matrix.
// 3. This solution avoids using additional space, and the matrix is rotated in place.

// Complexity Analysis
// - Time Complexity: O(n * m), where n is the number of rows and m is the number of columns.
//   - The transposition requires visiting each element once, and reversing each row takes O(m) time.
// - Space Complexity: O(1), since the rotation is done in place and no additional space is used.