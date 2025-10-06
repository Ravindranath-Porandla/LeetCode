class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:

        ROWS, COLS = len(grid), len(grid[0])
        directions = [[1, 0], [-1, 0], [0, 1], [0, -1]]
        n = len(grid)

        from collections import deque

        def check(t):
            visited = set()
            q = deque([(0, 0)])
            visited.add((0, 0))

            if grid[0][0] > t:
                return False

            while q:
                r, c = q.popleft()

                if r == (n - 1) and c == (n - 1):
                    return True

                for dr, dc in directions:
                    nr, nc = r + dr, c + dc
                    if (
                        0 <= nr < ROWS
                        and 0 <= nc < COLS
                        and (nr, nc) not in visited
                        and grid[nr][nc] <= t
                    ):
                        visited.add((nr, nc))
                        q.append((nr, nc))
            return False

        l, r = grid[0][0], n * n - 1
        res = n * n - 1

        while l <= r:
            mid = (l + r) // 2
            if check(mid):  # return True for the threshold is workable
                r = mid - 1
                res = min(res, mid)
            else:
                l = mid + 1

        return res
