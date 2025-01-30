// https://leetcode.com/problems/valid-sudoku/
class Solution {
public:
    bool isUniqueRow(vector<vector<char>>& board, int row)
    {
        if(row==board.size())
            return true;
        unordered_set<int> st;
        for(int j=0; j<board[row].size(); j++)
        {
            if(board[row][j]!='.')
            {
                int number = board[row][j] - '0';
                if(st.find(number)!=st.end())
                    return false;
                st.insert(number);
            }
        }
        return isUniqueRow(board, row+1);
    }

    bool isUniqueCol(vector<vector<char>>& board, int col)
    {
        if(col==board.size())
            return true;
        unordered_set<int> st;
        for(int i=0; i<board.size(); i++)
        {
            if(board[i][col]!='.')
            {
                int number = board[i][col] - '0';
                if(st.find(number)!=st.end())
                    return false;
                st.insert(number);
            }
        }
        return isUniqueCol(board, col+1);
    }

    bool isUniqueMatrix(vector<vector<char>>& board, int startRow, int startCol) {
        unordered_set<int> st;
        for (int i = startRow; i < startRow + 3; i++) {
            for (int j = startCol; j < startCol + 3; j++) {
                if (board[i][j] != '.') {
                    int number = board[i][j] - '0';
                    if (st.find(number) != st.end())
                        return false;
                    st.insert(number);
                }
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                if (!isUniqueMatrix(board, i, j))
                    return false;
            }
        }
        return isUniqueRow(board, 0) && isUniqueCol(board, 0);
    }
};

// Approach
// 1. To validate a Sudoku board, we need to check if all rows, columns, and 3x3 subgrids (also called matrices) contain no duplicate numbers (ignoring the empty cells marked with '.').
// 2. We perform the following checks:
//    - Row Validation: For each row, check if there are any duplicates among the numbers (excluding the '.' character). This is done using an unordered_set to track numbers that have already appeared in the row.
//    - Column Validation: For each column, check if there are any duplicates, similarly using an unordered_set.
//    - 3x3 Subgrid Validation: Check each 3x3 subgrid. A subgrid is identified by its top-left corner, and we check if there are any duplicates within the grid, excluding the '.' characters.
// 3. For row and column checks, we recursively validate from row 0 to row 8, and similarly for columns, until all rows and columns are validated.
// 4. We iterate over the board to validate each 3x3 subgrid and ensure that no numbers repeat in any of them.
// 5. If all checks pass, return `true`, otherwise return `false` if any duplicate is found in a row, column, or subgrid.
// Recursion is used for row and column validation to simplify the structure, making the function more readable by using recursion to handle subsequent rows and columns.

// Complexity Analysis
// Time Complexity:
// - The time complexity of the solution is O(1), which is constant. This is because the board always has a fixed size of 9x9 (81 cells), and we perform a constant amount of work (checking each cell and performing insertions into the hash set) for each cell.
// - For each row and column, we check 9 cells, and for each subgrid, we check 9 cells. This results in a constant number of operations that do not depend on the input size.
// Space Complexity:
// - The space complexity is O(1), since the extra space used is constant, determined by the size of the unordered sets used for checking duplicates. The space is used for each row, column, and 3x3 subgrid during validation, which is constant for a 9x9 board.

