class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& board,
             vector<vector<int>>& vis, int drow[], int dcol[], int n, int m) {
        vis[row][col] = 1;

        for (int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                !vis[nrow][ncol] && board[nrow][ncol] == 'O') {
                dfs(nrow, ncol, board, vis, drow, dcol, n, m);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));
        int drow[] = {0, 0, -1, 1};
        int dcol[] = {-1, 1, 0, 0};

        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O' && !vis[i][0]) {
                dfs(i, 0, board, vis, drow, dcol, n, m);
            }
            if (board[i][n - 1] == 'O' && !vis[i][n - 1]) {
                dfs(i, n - 1, board, vis, drow, dcol, n, m);
            }
        }

        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O' && !vis[0][j]) {
                dfs(0, j, board, vis, drow, dcol, n, m);
            }
            if (board[m - 1][j] == 'O' && !vis[m - 1][j]) {
                dfs(m - 1, j, board, vis, drow, dcol, n, m);
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j] == 1) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};