class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int left = 0;
        int right = 0;
        int ans = 0;
        unordered_map<char, int> mp;
        int max_count = 0;

        while (right < n) {
            mp[s[right]]++;
            max_count = max(max_count, mp[s[right]]);

            while (left <= right && (right - left + 1 - max_count) > k) {
                mp[s[left]]--;
                if (mp[s[left]] == 0) {
                    mp.erase(s[left]);
                }
                left++;
            }
            ans = max(ans, right - left + 1);
            right++;
        }
        return ans;
    }
};