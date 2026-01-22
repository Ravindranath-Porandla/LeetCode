class Solution:
    def minimumPairRemoval(self, nums: list[int]) -> int:
        ops = 0

        while True:
            is_sorted = True
            for i in range(len(nums) - 1):
                if nums[i] > nums[i + 1]:
                    is_sorted = False
                    break

            if is_sorted:
                return ops

            min_sum = -1
            min_idx = -1

            for i in range(len(nums) - 1):
                current_sum = nums[i] + nums[i + 1]
                if min_idx == -1 or current_sum < min_sum:
                    min_sum = current_sum
                    min_idx = i

            nums[min_idx] = min_sum
            del nums[min_idx + 1]
            ops += 1
