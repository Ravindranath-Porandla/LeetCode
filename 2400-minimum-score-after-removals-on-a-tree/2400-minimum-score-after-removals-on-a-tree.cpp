class Solution {
public:
    void dfs(int node, int parent, unordered_map<int, vector<int>> &adj, vector<int> &nums, vector<int> &inTime, vector<int> &outTime, vector<int> &XORS, int &timer){
        XORS[node] = nums[node];
        inTime[node] = timer++;

        for(auto &ngbr : adj[node]){
            if(ngbr != parent){
                dfs(ngbr, node, adj, nums, inTime, outTime, XORS, timer);
                XORS[node] ^= XORS[ngbr];
            }
        }

        outTime[node] = timer++;
    }

    bool ancestor(int u, int v, vector<int> &inTime, vector<int> &outTime){
        return (inTime[v] > inTime[u]) && (outTime[v] < outTime[u]);
    }

    int getScore(int a, int b, int c){
        int minValue = min({a, b, c});
        int maxValue = max({a, b, c});

        return maxValue - minValue;
    }
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        unordered_map<int, vector<int>> adj;

        for(auto &edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> XORS(n, 0);
        vector<int> inTime(n, 0);
        vector<int> outTime(n, 0);
        int timer = 0;

        dfs(0, -1, adj, nums, inTime, outTime, XORS, timer);

        int res = INT_MAX;
        for(int u = 1; u < n; u++){
            for(int v = u + 1; v < n; v++){
                int xor1;
                int xor2;
                int xor3;

                if(ancestor(u, v, inTime, outTime)){
                    xor1 = XORS[u] ^ XORS[v];
                    xor2 = XORS[v];
                    xor3 = XORS[0] ^ xor1 ^ xor2;
                } else if(ancestor(v, u, inTime, outTime)){
                    xor1 = XORS[u];
                    xor2 = XORS[v] ^ XORS[u];
                    xor3 = XORS[0] ^ xor1 ^ xor2;
                } else {
                    xor1 = XORS[u];
                    xor2 = XORS[v];
                    xor3 = XORS[0] ^ xor1 ^ xor2;
                }

                res = min(res, getScore(xor1, xor2, xor3));
            }
        }

        return res;
    }
};