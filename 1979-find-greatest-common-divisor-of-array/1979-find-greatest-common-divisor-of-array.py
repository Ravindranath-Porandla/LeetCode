class Solution:
    def findGCD(self, nums: List[int]) -> int:
        nums.sort()
        n = len(nums)
        
        res = 1
        
        for i in range(1, nums[0] + 1):
            if (nums[n - 1] % i == 0) and (nums[0] % i== 0):
                res = i
        return res