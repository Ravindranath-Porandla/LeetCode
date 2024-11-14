class Solution {
public:
    bool find(int row, int col, vector<vector<char>>& board, string word,
              int idx, int delrows[], int delcols[]) {
        if (idx == word.size()) {
            return true;
        }
        char temp = board[row][col];
        board[row][col] = '*';
        for (int i = 0; i < 4; i++) {
            int nrow = row + delrows[i];
            int ncol = col + delcols[i];

            if (nrow >= 0 && ncol >= 0 && nrow < board.size() &&
                ncol < board[0].size()) {
                if (board[nrow][ncol] == word[idx]) {
                    if (find(nrow, ncol, board, word, idx + 1, delrows,
                             delcols)) {
                        return true;
                    }
                }
            }
        }
        board[row][col] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        int delrows[] = {0, 0, 1, -1};
        int delcols[] = {-1, 1, 0, 0};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (find(i, j, board, word, 1, delrows, delcols)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};