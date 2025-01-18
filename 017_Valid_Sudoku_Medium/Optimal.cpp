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