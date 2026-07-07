class Solution:
    def sumAndMultiply(self, n: int) -> int:
        num = 0
        rev = 0
        while(n > 0):
            a = n % 10
            rev = rev * 10 + a
            n = n // 10
        n = rev
        while n:
            digit = n % 10
            if digit > 0:
                num = (num * 10) + digit
            n //= 10

        res = num
        digits_sum = 0

        while num:
            digits_sum += num % 10
            num //= 10

        return res * digits_sum
