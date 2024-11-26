class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> vec(n, 0);

        for(int i = 0; i < edges.size(); i++){
            vec[edges[i][1]]++;
        }

        int cnt = 0;
        int ans = -1;

        for(int i = 0; i < n; i++){
            if(vec[i] == 0){
                cnt++;
                if(ans == -1){
                    ans = i;
                }
            }
            if(cnt > 1)
                return -1;
        }
        return ans;
    }
};