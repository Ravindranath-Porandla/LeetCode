class Solution:
    def numWaterBottles(self, numBottles: int, numExchange: int) -> int:
        ans = numBottles
        emptyBottles = numBottles
        filledBottles = 0

        while emptyBottles >= numExchange:
            filledBottles = int(emptyBottles / numExchange)
            ans += filledBottles
            emptyBottles -= int(filledBottles * numExchange)
            emptyBottles += filledBottles

        return int(ans)
