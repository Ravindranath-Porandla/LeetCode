class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int j = 0;
        unordered_map<char, int> mp;
        while(j < k){
            mp[blocks[j]]++;
            j++;
        }
        int ans = mp['W'];
        int i = 0;

        while(j < n){
            mp[blocks[i]]--;
            if(mp[blocks[i]] == 0){
                mp.erase(blocks[i]);
            }
            i++;
            mp[blocks[j]]++;
            ans = min(ans, mp['W']);
            j++;
        }
        return ans;
    }
};