class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        current_maxi = prices[len(prices) - 1]
        result = 0

        for i in range(len(prices) - 1, -1, -1):
            current_maxi = max(current_maxi, prices[i])
            result = max(result, current_maxi - prices[i])

        return result
