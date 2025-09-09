class Solution:
    def peopleAwareOfSecret(self, n: int, delay: int, forget: int) -> int:
        mod = 10**9 + 7
        dp = [0] * (n + 1)
        dp[1] = 1

        noOfPeopleWithSecret = 0

        for i in range(2, n + 1):
            noOfNewPeopleWithSecret = dp[i - delay] if i - delay >= 1 else 0

            noOfPeopleForgetSecret = dp[i - forget] if i - forget >= 1 else 0

            noOfPeopleWithSecret = (
                noOfPeopleWithSecret
                + noOfNewPeopleWithSecret
                - noOfPeopleForgetSecret
                + mod
            ) % mod

            dp[i] = noOfPeopleWithSecret

        ans = 0
        for i in range(n - forget + 1, n + 1):
            if i >= 1:
                ans = (ans + dp[i]) % mod

        return ans
