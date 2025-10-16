class Solution:
    def findSmallestInteger(self, nums: List[int], value: int) -> int:
        arr = [i for i in range(value)]
        for i in nums:
            x = i % value
            if x < 0:
                arr[x + value] += 1
            else:
                arr[x] += value
        return min(arr)
