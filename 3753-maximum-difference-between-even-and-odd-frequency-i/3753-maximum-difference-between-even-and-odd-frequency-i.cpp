class Solution {
public:
    int maxDifference(string s) {
        vector<int> freq(26);
        int maxi = 0;
        int mini = s.size();
        for (char c : s)
            freq[c - 'a']++;
        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 != 0)
                maxi = max(maxi, freq[i]);
            if (freq[i] % 2 == 0 && freq[i] > 0)
                mini = min(mini, freq[i]);
        }
        return maxi - mini;
    }
};