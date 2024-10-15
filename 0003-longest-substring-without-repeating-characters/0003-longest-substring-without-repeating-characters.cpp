class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int left = 0;
        int right = 0;
        int ans = 0;

        unordered_map<char, int> mp;

        while (right < n) {
            mp[s[right]]++;

            while (left <= right && mp[s[right]] > 1) {
                mp[s[left]]--;
                left++;

                if (mp[s[left]] == 0) {
                    mp.erase(mp[s[left]]);
                }
            }
            ans = max(ans, right - left + 1);
            right++;
        }
        return ans;
    }
};