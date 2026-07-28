from collections import Counter

class Solution:
    def smallestPalindrome(self, s: str) -> str:
        freq = Counter(s)

        first_half = []
        middle = ""

        for ch in sorted(freq):
            first_half.append(ch * (freq[ch] // 2))
            if freq[ch] % 2 == 1:
                middle = ch

        first_half = "".join(first_half)
        return first_half + middle + first_half[::-1]