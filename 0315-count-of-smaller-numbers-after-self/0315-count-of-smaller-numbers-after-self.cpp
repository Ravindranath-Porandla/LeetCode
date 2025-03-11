class Solution {
public:
    int n;
    vector<int> bit;
    
    void update(int val, int id){
        while(id <= n){
            bit[id] += val;
            id += (id & -id);
        }
    }

    int query(int id){
        int ans = 0;
        while(id > 0){
            ans += bit[id];
            id -= (id & -id);
        }
        return ans;
    }
    vector<int> countSmaller(vector<int>& nums) {
        n = nums.size();
        bit.resize(n + 1, 0);
        vector<pair<int, int>> vec;
        for(int i = 0; i < n; i++){
            vec.push_back({nums[i], i});
        }

        sort(vec.begin(), vec.end());

        vector<int> res(n, 0);

        for(auto v : vec){
            update(1, v.second + 1);
            res[v.second] = query(n) - query(v.second + 1);
        }

        return res;
    }
};