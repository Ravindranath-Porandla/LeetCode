class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        
        vector<int> deg(n, 0);
        
        for(auto &vec : roads){
            int u = vec[0];
            int v = vec[1];
            
            deg[u]++;
            deg[v]++;
        }
        
        sort(begin(deg), end(deg));
        
        long long int ans = 0;
        int imp = 1;
        for(int i = 0; i < n; i++){
            ans += deg[i] * (long long)imp;
            imp++;
        }
        
        return ans;
    }
};