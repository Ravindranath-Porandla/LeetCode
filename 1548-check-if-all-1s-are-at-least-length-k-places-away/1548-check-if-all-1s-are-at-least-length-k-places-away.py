class Solution:
    def kLengthApart(self, nums, k):
        last_occurred = -1
        for i, num in enumerate(nums):
            if num == 1:
                if last_occurred != -1 and i - last_occurred - 1 < k:
                    return False
                last_occurred = i
        return True
