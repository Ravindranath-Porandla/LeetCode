class Solution:
    def minCost(self, colors: str, neededTime: list[int]) -> int:
        cost = 0
        n = len(colors)
        prev = colors[0]

        for i in range(1, n):
            curr = colors[i]
            if curr == prev:
                cost += min(neededTime[i], neededTime[i - 1])
                neededTime[i] = max(neededTime[i], neededTime[i - 1])
            prev = curr

        return cost
