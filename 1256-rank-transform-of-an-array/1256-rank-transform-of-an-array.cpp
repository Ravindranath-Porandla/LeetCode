class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if(n == 0)  return {};
        vector<int> ans(n, 0);

        vector<vector<int>> temp;
        for (int i = 0; i < n; i++) {
            temp.push_back({arr[i], i});
        }

        sort(temp.begin(), temp.end());
        int rank = 1;
        ans[temp[0][1]] = 1;

        for(int i = 1; i < n; i++){
            if(temp[i][0] != temp[i - 1][0]){
                rank++;
            }
            ans[temp[i][1]] = rank;
        }
        return ans;
    }
};