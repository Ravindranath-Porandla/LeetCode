class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int left = 0;
        int right = 0;
        int max_count = 0;
        unordered_map<char, int> mp;
        int ans = 0;

        while (right < n) {
            mp[s[right]]++;
            max_count = max(max_count, mp[s[right]]);

            while (right - left + 1 - max_count > k && left <= right) {
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