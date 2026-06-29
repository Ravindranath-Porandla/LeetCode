class Solution:
    def numOfStrings(self, a: List[str], s: str) -> int:
        return sum(t in s for t in a)