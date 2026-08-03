class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            unordered_set<char> rowSet, colSet;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (rowSet.count(board[i][j])) return false;
                    rowSet.insert(board[i][j]);
                }
                if (board[j][i] != '.') {
                    if (colSet.count(board[j][i])) return false;
                    colSet.insert(board[j][i]);
                }
            }
        }

        for (int row = 0; row < 9; row += 3) {
            for (int col = 0; col < 9; col += 3) {
                unordered_set<char> blockSet;
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        char val = board[row + i][col + j];
                        if (val != '.') {
                            if (blockSet.count(val)) return false;
                            blockSet.insert(val);
                        }
                    }
                }
            }
        }

        return true;
    }
};

