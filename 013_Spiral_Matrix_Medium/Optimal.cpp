// https://leetcode.com/problems/spiral-matrix/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> ans;

        int left = 0;
        int right = m - 1;
        int top = 0;
        int bottom = n - 1;

        while(top<=bottom && left<=right)
        {
            for(int i=left; i<=right; i++)
                ans.push_back(matrix[top][i]);
            top++;
            for(int i=top; i<=bottom; i++)
                ans.push_back(matrix[i][right]);
            right--;
            if(top<=bottom)
            {
                for(int i=right; i>=left; i--)
                    ans.push_back(matrix[bottom][i]);
                bottom--;
            }
            if(left<=right)
            {
                for(int i=bottom; i>=top; i--)
                    ans.push_back(matrix[i][left]);
                left++;
            }
        }

        return ans;
    }
};

// Approach
// 1. We will traverse the matrix in a spiral order by maintaining four boundaries:
//    - `top` for the top row
//    - `bottom` for the bottom row
//    - `left` for the leftmost column
//    - `right` for the rightmost column
// 2. Start from the top-left of the matrix and keep moving in a clockwise direction:
//    - Traverse the top row from left to right.
//    - Traverse the right column from top to bottom.
//    - Traverse the bottom row from right to left (if still within bounds).
//    - Traverse the left column from bottom to top (if still within bounds).
// 3. After completing each traversal, adjust the boundaries to move inward until all elements are covered.

// Complexity Analysis
// - Time Complexity: O(n * m), where n is the number of rows and m is the number of columns. 
//   Every element in the matrix is visited once.
// - Space Complexity: O(n * m), for the resultant vector to store the spiral order.