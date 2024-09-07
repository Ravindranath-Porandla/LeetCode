class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n == 0)  return 0;
        int left = 0;
        int right = 0;

        unordered_map<int, int> mp;
        int ans = INT_MIN;
        while (left <= right && right < n) {
            mp[s[right]]++;
            while (left <= right && mp[s[right]] > 1) {
                mp[s[left]]--;
                if(mp[s[left]] == 0)
                    mp.erase(s[left]);
                left++;
            }
            ans = max(ans, right - left + 1);
            right++;
        }
        return ans;
    }
};