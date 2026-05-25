from collections import deque


class Solution:
    def canReach(self, s: str, minJump: int, maxJump: int) -> bool:

        n = len(s)

        q = deque([0])

        vis = [0] * n
        vis[0] = 1

        further = 0

        while q:

            idx = q.popleft()

            if idx == n - 1:
                return True

            l = max(further + 1, idx + minJump)
            r = min(idx + maxJump, n - 1)

            for k in range(l, r + 1):

                if s[k] == "0" and not vis[k]:

                    vis[k] = 1
                    q.append(k)

            further = max(further, r)

        return False
