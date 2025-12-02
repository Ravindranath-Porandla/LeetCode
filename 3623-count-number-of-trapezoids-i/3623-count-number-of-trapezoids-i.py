from typing import List
from collections import defaultdict


class Solution:
    def countTrapezoids(self, points: List[List[int]]) -> int:
        MOD = 10**9 + 7
        INV2 = (MOD + 1) // 2

        freq = defaultdict(int)
        for x, y in points:
            freq[y] += 1

        sumF = 0
        sumF2 = 0

        for c in freq.values():
            if c >= 2:
                f = c * (c - 1) // 2
                f %= MOD
                sumF = (sumF + f) % MOD
                sumF2 = (sumF2 + f * f) % MOD

        ans = (sumF * sumF) % MOD
        ans = (ans - sumF2 + MOD) % MOD
        ans = ans * INV2 % MOD

        return ans
