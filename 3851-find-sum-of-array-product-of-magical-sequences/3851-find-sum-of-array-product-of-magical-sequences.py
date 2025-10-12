MOD = 10**9 + 7


class Solution:
    def magicalSum(self, m, k, nums):
        n = len(nums)

        powNum = [[1] * (m + 1) for _ in range(n)]
        for i in range(n):
            for j in range(1, m + 1):
                powNum[i][j] = powNum[i][j - 1] * nums[i] % MOD

        C = [[0] * (m + 1) for _ in range(m + 1)]
        for i in range(m + 1):
            C[i][0] = C[i][i] = 1
            for j in range(1, i):
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD

        from functools import lru_cache

        @lru_cache(None)
        def dfs(pos, carry, used, ones):
            if pos == n:
                extra = bin(carry).count("1")
                return 1 if used == m and ones + extra == k else 0

            ans = 0
            for cnt in range(m - used + 1):
                total = carry + cnt
                bit = total & 1
                ncarry = total >> 1
                nones = ones + bit
                sub = dfs(pos + 1, ncarry, used + cnt, nones)
                if not sub:
                    continue
                ways = C[m - used][cnt]
                prod = powNum[pos][cnt]
                ans = (ans + sub * ways % MOD * prod) % MOD
            return ans

        return dfs(0, 0, 0, 0)
