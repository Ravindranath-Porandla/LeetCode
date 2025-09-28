class Solution:
    def largestPerimeter(self, nums: List[int]) -> int:
        nums.sort(reverse=True)
        return next(
            (x + y + z for x, y, z in zip(nums, nums[1:], nums[2:]) if x < y + z), 0
        )
