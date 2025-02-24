class Solution {
public:
    unordered_map<int, int> checkpoint;
    vector<int> explored;

    int tracePath(vector<vector<int>>& graph, int target, int step) {
        if (target == 0) {
            checkpoint[target] = step;
            return 1;
        }

        explored[target] = 1;

        for (int i = 0; i < graph[target].size(); i++) {
            if (!explored[graph[target][i]]) {
                if (tracePath(graph, graph[target][i], step + 1)) {
                    checkpoint[target] = step;
                    return 1;
                }
            }
        }

        return 0;
    }

    int searchMaxProfit(vector<vector<int>>& graph, int player, int step,
                        vector<int>& profit) {
        explored[player] = 1;

        int gain;

        if (checkpoint.find(player) != checkpoint.end() &&
            checkpoint[player] > step) {
            gain = profit[player];
        } else if (checkpoint.find(player) != checkpoint.end() &&
                   checkpoint[player] < step) {
            gain = 0;
        } else if (checkpoint.find(player) != checkpoint.end()) {
            gain = profit[player] / 2;
        } else {
            gain = profit[player];
        }

        int maxProfit = -INT_MAX + 10000;

        int isLeaf = 1;

        for (int i = 0; i < graph[player].size(); i++) {
            if (!explored[graph[player][i]]) {
                isLeaf = 0;
                maxProfit = max(maxProfit,
                                gain + searchMaxProfit(graph, graph[player][i],
                                                       step + 1, profit));
            }
        }

        if (isLeaf) {
            return gain;
        }

        return maxProfit;
    }

    int mostProfitablePath(vector<vector<int>>& links, int target,
                           vector<int>& profit) {
        explored = vector<int>(profit.size());

        vector<vector<int>> graph(profit.size());

        for (int i = 0; i < links.size(); i++) {
            graph[links[i][0]].push_back(links[i][1]);
            graph[links[i][1]].push_back(links[i][0]);
        }

        tracePath(graph, target, 0);

        explored = vector<int>(profit.size());

        return searchMaxProfit(graph, 0, 0, profit);
    }
};
