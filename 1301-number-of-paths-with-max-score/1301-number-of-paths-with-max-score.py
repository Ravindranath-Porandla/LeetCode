class Solution:
    def pathsWithMaxScore(self, board: List[str]) -> List[int]:
        MOD = 10**9 + 7
        n = len(board)

        dp_sum = [[-1] * n for _ in range(n)]
        dp_paths = [[0] * n for _ in range(n)]

        dp_sum[n - 1][n - 1] = 0
        dp_paths[n - 1][n - 1] = 1

        for r in range(n - 1, -1, -1):
            for c in range(n - 1, -1, -1):
                if board[r][c] == "X" or dp_sum[r][c] == -1:
                    continue

                current_sum = dp_sum[r][c]
                current_paths = dp_paths[r][c]

                directions = [(r - 1, c), (r, c - 1), (r - 1, c - 1)]

                for nr, nc in directions:
                    if 0 <= nr < n and 0 <= nc < n and board[nr][nc] != "X":
                        cell_val = 0
                        if "1" <= board[nr][nc] <= "9":
                            cell_val = int(board[nr][nc])

                        next_sum = current_sum + cell_val

                        if next_sum > dp_sum[nr][nc]:
                            dp_sum[nr][nc] = next_sum
                            dp_paths[nr][nc] = current_paths
                        elif next_sum == dp_sum[nr][nc]:
                            dp_paths[nr][nc] = (dp_paths[nr][nc] + current_paths) % MOD

        if dp_sum[0][0] == -1:
            return [0, 0]

        return [dp_sum[0][0], dp_paths[0][0]]
