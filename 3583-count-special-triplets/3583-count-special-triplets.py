class Solution:
    def specialTriplets(self, nums: List[int]) -> int:
        right = {}
        left = {}
        n = len(nums)

        for i in range(2, n):
            right[nums[i]] = right.get(nums[i], 0) + 1

        left[nums[0]] = 1

        cnt = 0
        mod = int(1e9 + 7)

        for i in range(1, n - 1):
            l = 0
            d = nums[i] * 2
            if d in left and left[d] > 0:
                l = left[d]
            r = 0
            if d in right and right[d] > 0:
                r = right[d]

            cnt = cnt + ((l * r) % mod) % mod
            right[nums[i + 1]] = right[nums[i + 1]] - 1
            left[nums[i]] = left.get(nums[i], 0) + 1

        return int(cnt % mod)
