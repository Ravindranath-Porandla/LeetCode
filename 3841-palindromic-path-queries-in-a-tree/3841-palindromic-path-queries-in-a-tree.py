import sys


class Solution:
    def palindromePath(
        self, n: int, edges: list[list[int]], s: str, queries: list[str]
    ) -> list[bool]:
        # Trees can be deep; push Python's recursion limit past the constraint (50,000)
        sys.setrecursionlimit(100005)

        # 1. Build Adjacency List
        adj = [[] for _ in range(n)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)

        LOG = 17  # 2^17 > 50,000
        up = [[0] * LOG for _ in range(n)]
        depth = [0] * n
        tin = [0] * n
        tout = [0] * n
        initial_mask = [0] * n
        s_list = list(s)

        timer = 0

        # 2. DFS for Euler Tour & Binary Lifting Precomputation
        def dfs(u, p, d, curr_mask):
            nonlocal timer
            timer += 1
            tin[u] = timer
            up[u][0] = p
            depth[u] = d

            # Precompute 2^i ancestors for Binary Lifting
            for i in range(1, LOG):
                up[u][i] = up[up[u][i - 1]][i - 1]

            char_bit = 1 << (ord(s_list[u]) - 97)
            initial_mask[u] = curr_mask ^ char_bit

            for v in adj[u]:
                if v != p:
                    dfs(v, u, d + 1, initial_mask[u])

            tout[u] = timer

        dfs(0, 0, 0, 0)

        # 3. Lowest Common Ancestor (LCA) via Binary Lifting
        def get_lca(u, v):
            if depth[u] < depth[v]:
                u, v = v, u

            # Level them up to the same depth
            diff = depth[u] - depth[v]
            for i in range(LOG):
                if (diff >> i) & 1:
                    u = up[u][i]

            if u == v:
                return u

            # Jump upwards together just below the LCA
            for i in range(LOG - 1, -1, -1):
                if up[u][i] != up[v][i]:
                    u = up[u][i]
                    v = up[v][i]

            return up[u][0]

        # 4. Fenwick Tree (Binary Indexed Tree) for Range Updates / Point Queries
        # bit tracks the *changes* (XOR deltas) to the path masks since the start
        bit = [0] * (n + 2)

        def add_xor(idx, val):
            while idx <= n:
                bit[idx] ^= val
                idx += idx & -idx

        def range_update_xor(l, r, val):
            add_xor(l, val)
            add_xor(r + 1, val)

        def point_query_xor(idx):
            res = 0
            while idx > 0:
                res ^= bit[idx]
                idx -= idx & -idx
            return res

        # 5. Process Queries
        ans = []
        for q in queries:
            parts = q.split()

            if parts[0] == "update":
                u = int(parts[1])
                c = parts[2]

                # Only update if the character actually changes
                if s_list[u] != c:
                    old_char_mask = 1 << (ord(s_list[u]) - 97)
                    new_char_mask = 1 << (ord(c) - 97)
                    diff = old_char_mask ^ new_char_mask

                    # Apply XOR difference to node and all its descendants
                    range_update_xor(tin[u], tout[u], diff)
                    s_list[u] = c

            else:
                u = int(parts[1])
                v = int(parts[2])
                lca = get_lca(u, v)

                # Current root-to-node mask = Initial mask XOR all recorded updates
                mask_u = initial_mask[u] ^ point_query_xor(tin[u])
                mask_v = initial_mask[v] ^ point_query_xor(tin[v])
                lca_char_mask = 1 << (ord(s_list[lca]) - 97)

                # Path mask logic: Shared paths cancel out, restore the LCA
                path_mask = mask_u ^ mask_v ^ lca_char_mask

                # A valid palindrome has at most 1 odd character (1 set bit)
                # n & (n - 1) == 0 checks if a number is a power of 2 (or 0)
                ans.append((path_mask & (path_mask - 1)) == 0)

        return ans
