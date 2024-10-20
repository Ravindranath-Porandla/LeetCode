class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& board,
             vector<vector<int>>& visited, int drows[], int dcols[]) {
        visited[row][col] = 1;
        board[row][col] = '.';

        for (int i = 0; i < 4; i++) {
            int nrow = row + drows[i];
            int ncol = col + dcols[i];
            if (nrow >= 0 && ncol >= 0 && nrow < board.size() &&
                ncol < board[0].size() && !visited[nrow][ncol] &&
                board[nrow][ncol] == 'X') {
                dfs(nrow, ncol, board, visited, drows, dcols);
            }
        }
    }
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));
        int cnt = 0;
        int drows[] = {-1, 1, 0, 0};
        int dcols[] = {0, 0, 1, -1};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && board[i][j] == 'X') {
                    cnt++;
                    dfs(i, j, board, visited, drows, dcols);
                }
            }
        }
        return cnt;
    }
};