class Solution {
public:
    int isZeros(vector<int>& freq) {
        for (int i : freq) {
            if (i != 0) {
                return false;
            }
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();
        if(n < m)   return {};

        vector<int> freq(26, 0);

        for (char ch : p) {
            freq[ch - 'a']++;
        }

        for (int i = 0; i < m; i++) {
            char ch = s[i];
            freq[ch - 'a']--;
        }

        vector<int> ans;
        if (isZeros(freq)) {
            ans.push_back(0);
        }

        int left = 0;
        int right = m - 1;

        while (right < n - 1) {
            freq[s[left] - 'a']++;
            left++;
            right++;
            freq[s[right] - 'a']--;
            if (isZeros(freq)) {
                ans.push_back(left);
            }
        }
        return ans;
    }
};