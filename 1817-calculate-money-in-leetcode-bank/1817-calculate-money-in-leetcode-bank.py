class Solution:
    def totalMoney(self, n: int) -> int:
        w = n // 7
        r = n % 7
        full_weeks_sum = w * 28 + 7 * (w * (w - 1) // 2)
        rem_sum = r * (1 + w) + (r * (r - 1) // 2)
        return full_weeks_sum + rem_sum
