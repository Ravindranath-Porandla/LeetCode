class Solution:
    def maxIncreasingSubarrays(self, nums):
        n = len(nums)
        if n == 0:
            return 0
        if n == 1:
            return 1

        end = [1] * n
        start = [1] * n

        for i in range(1, n):
            if nums[i] > nums[i - 1]:
                end[i] = end[i - 1] + 1

        for i in range(n - 2, -1, -1):
            if nums[i] < nums[i + 1]:
                start[i] = start[i + 1] + 1

        ans = 1
        for k in range(n - 1):
            ans = max(ans, min(end[k], start[k + 1]))

        return ans