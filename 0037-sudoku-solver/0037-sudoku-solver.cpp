class Solution {
public:
    int is_safe(vector<vector<char>>& board, int row, int col, char digit) {
        for (int i = 0; i <= 8; i++) {
            if (board[row][i] == digit) {
                return 0;
            }
        }
        for (int i = 0; i <= 8; i++) {
            if (board[i][col] == digit) {
                return 0;
            }
        }
        int x = row / 3 * 3;
        int y = col / 3 * 3;
        for (int i = x; i <= x + 2; i++) {
            for (int j = y; j <= y + 2; j++) {
                if (board[i][j] == digit) {
                    return 0;
                }
            }
        }
        return 1;
    }
    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i <= 8; i++) {
            for (int j = 0; j <= 8; j++) {
                if (board[i][j] == '.') {
                    for (char c = '1'; c <= '9'; c++) {
                        if (is_safe(board, i, j, c)) {
                            board[i][j] = c;
                            if (solve(board))
                                return true;
                            else
                                board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) { solve(board); }
};