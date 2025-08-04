class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int left = 0;
        int right = 0;
        unordered_map<int, int> mp;
        int ans = 0;

        while(right < n){
            mp[fruits[right]]++;
            while(left <= right && mp.size() > 2){
                mp[fruits[left]]--;
                if(mp[fruits[left]] == 0){
                    mp.erase(fruits[left]);
                }
                left++;
            }
            int cnt = 0;
            for(auto &it : mp){
                cnt += it.second;
            }
            ans = max(ans, cnt);
            right++;
        }

        return ans;
    }
};