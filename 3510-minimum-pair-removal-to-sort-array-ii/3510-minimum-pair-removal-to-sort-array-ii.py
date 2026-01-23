class Solution:
    def minimumPairRemoval(self, nums: List[int]) -> int:
        n = len(nums)
        a = [int(x) for x in nums]
        l = [i - 1 for i in range(n)]
        r = [i + 1 for i in range(n)]
        r[n - 1] = -1
        alive = [True] * n

        bad = 0
        for i in range(1, n):
            if a[i] < a[i - 1]:
                bad += 1

        import heapq

        pq = []
        for i in range(n - 1):
            heapq.heappush(pq, (a[i] + a[i + 1], i))

        ops = 0

        while bad > 0:
            s, i = heapq.heappop(pq)
            if not alive[i] or r[i] == -1:
                continue
            j = r[i]
            if not alive[j] or a[i] + a[j] != s:
                continue

            li, rj = l[i], r[j]

            if li != -1 and a[i] < a[li]:
                bad -= 1
            if rj != -1 and a[rj] < a[j]:
                bad -= 1
            if a[j] < a[i]:
                bad -= 1

            a[i] += a[j]
            alive[j] = False
            r[i] = rj
            if rj != -1:
                l[rj] = i

            if li != -1 and a[i] < a[li]:
                bad += 1
            if rj != -1 and a[rj] < a[i]:
                bad += 1

            if li != -1:
                heapq.heappush(pq, (a[li] + a[i], li))
            if rj != -1:
                heapq.heappush(pq, (a[i] + a[rj], i))

            ops += 1

        return ops
