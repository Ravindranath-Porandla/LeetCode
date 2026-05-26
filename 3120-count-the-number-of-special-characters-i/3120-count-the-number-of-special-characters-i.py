class Solution:
    def numberOfSpecialChars(self, word: str) -> int:
        lower = set()
        upper = set()
        for c in word:
            if c.islower():
                lower.add(c)
            else:
                upper.add(c.lower())
        return len(lower & upper)
