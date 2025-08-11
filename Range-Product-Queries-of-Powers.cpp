class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<long long> powers;
        int mod = 1e9 + 7;

        for(int i = 0; i < 32; i++){
            if(n & (1 << i))
                powers.push_back(1 << i);
        }

        vector<int> ans;
        for(auto &q : queries){
            int left = q[0];
            int right =  q[1];
            long long a = 1;

            for(int i = left; i <= right; i++){
                a = (a * powers[i]) % mod;
            }
            ans.push_back((int)a);
        }

        return ans;
    }
};