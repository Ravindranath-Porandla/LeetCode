class Solution:
    def maxTotalValue(self, A: List[int], k: int) -> int:
        return k * max(A) - k * min(A)
