class Solution:
    def minTime(self, skill: list[int], mana: list[int]) -> int:
        n = len(skill)
        m = len(mana)
        prevEnd = [0] * n

        prevEnd[0] = skill[0] * mana[0]
        for i in range(1, n):
            prevEnd[i] = prevEnd[i - 1] + skill[i] * mana[0]

        for j in range(1, m):
            delay = 0
            time = 0
            for i in range(n):
                if time >= prevEnd[i]:
                    time += skill[i] * mana[j]
                else:
                    delay += (prevEnd[i] - time)
                    time = prevEnd[i] + skill[i] * mana[j]

            prevEnd[0] = delay + skill[0] * mana[j]
            for i in range(1, n):
                prevEnd[i] = prevEnd[i - 1] + skill[i] * mana[j]

        return prevEnd[-1]