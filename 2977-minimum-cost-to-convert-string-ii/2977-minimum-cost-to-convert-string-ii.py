class Solution:
    def minimumCost(self, source: str, target: str, original: List[str], changed: List[str], cost: List[int]) -> int:

        graph, dict_costs = defaultdict(dict), {}
        for u, v, c in zip(original, changed, cost):
            graph[u][v] = min(c, graph[u].get(v, inf))
       
        def calc_cost(source, target):
            if source in dict_costs:
                return dict_costs[source].get(target, inf)
            heap, memo = [(0, source)], {source : 0}
            while heap:
                cost_current, word = heappop(heap)
                if cost_current == memo[word]:
                    for neighbor, cost_neighbor in graph[word].items():
                        cost_new = cost_neighbor + cost_current
                        if cost_new < memo.get(neighbor, inf):
                            memo[neighbor] = cost_new
                            heappush(heap, (cost_new, neighbor))
            dict_costs[source] = memo
            return memo.get(target, inf)

        def build_trie(text):
            root = {}
            for word in text:
                node = root
                for ch in word:
                    node = node.setdefault(ch, {})
                node['#'] = word
            return root 
      
        n = len(source)
        root_original, root_changed = build_trie(original), build_trie(changed)
        heap, min_costs = [(0, -1)], [inf] * n
        while heap:
            cost_current, start = heappop(heap)
            if start == n-1:
                return cost_current
            if cost_current <= min_costs[start]:
                start += 1
                if source[start] == target[start] and min_costs[start] > cost_current:
                    min_costs[start] = cost_current
                    heappush(heap, (cost_current, start))
                node_original, node_changed = root_original, root_changed
                for end in range(start, n):
                    node_original = node_original.get(source[end])
                    node_changed = node_changed.get(target[end])
                    if not node_original or not node_changed:
                        break
                    if '#' in node_original and '#' in node_changed:
                        cost_new = cost_current + calc_cost(node_original['#'], node_changed['#'])
                        if cost_new < min_costs[end]:
                            min_costs[end] = cost_new
                            heappush(heap, (cost_new, end))
        return -1