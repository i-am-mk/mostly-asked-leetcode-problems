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