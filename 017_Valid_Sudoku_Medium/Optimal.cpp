// https://leetcode.com/problems/valid-sudoku/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rows[9];
        unordered_set<char> cols[9];
        unordered_set<char> boxes[9];
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                if(board[i][j]=='.')
                    continue;
                
                char value = board[i][j];
                int boxIndex = (i/3)*3+(j/3);
                if(rows[i].count(value) || cols[j].count(value) || boxes[boxIndex].count(value))
                    return false;
                
                rows[i].insert(value);
                cols[j].insert(value);
                boxes[boxIndex].insert(value);
            }
        }
        return true;
    }
};

// Approach
// 1. To validate a Sudoku board, we need to check if all rows, columns, and 3x3 subgrids (boxes) contain unique numbers (ignoring empty cells marked as '.').
// 2. We use three arrays of unordered sets:
//    - `rows[i]`: To store the unique values in row `i`.
//    - `cols[j]`: To store the unique values in column `j`.
//    - `boxes[k]`: To store the unique values in the k-th 3x3 subgrid, where `k = (i / 3) * 3 + (j / 3)` for the cell at position (i, j).
// 3. As we iterate over each cell in the 9x9 grid, for each non-empty cell, we check:
//    - If the value is already present in the corresponding row, column, or subgrid set. If so, return `false`.
//    - If no duplicate is found, insert the value into the respective row, column, and subgrid sets.
// 4. If no duplicates are found after checking all cells, return `true` indicating the board is valid.

// Complexity Analysis
// Time Complexity:
// - The time complexity of this solution is O(1), as the board size is fixed at 9x9 (81 cells).
// - For each cell, we perform constant time operations (checking and inserting into sets), leading to a constant number of operations.
// Space Complexity:
// - The space complexity is O(1), as the space used by the sets is constant. 
//   We only need space for 9 sets for rows, columns, and subgrids, all of which have a fixed size of 9.