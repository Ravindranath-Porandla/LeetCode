class Solution:
    def makeTheIntegerZero(self, n1: int, n2: int) -> int:
        for op in range(1, 61):
            rem = n1 - op * n2
            if rem < op:
                continue
            pop = bin(rem).count("1")
            if pop <= op <= rem:
                return op
        return -1
