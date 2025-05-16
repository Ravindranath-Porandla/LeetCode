class Solution {
public:
    int hamDist(const string& str1, const string& str2) {
        if (str1.size() != str2.size())
            return -1;
        int cnt = 0;
        for (int i = 0; i < str1.size(); i++)
            if (str1[i] != str2[i])
                cnt++;
        return cnt;
    }

    vector<string> getWordsInLongestSubsequence(vector<string>& words,
                                                vector<int>& groups) {
        int n = words.size();
        vector<int> dp(n, 1);
        vector<int> parent(n, -1);
        int maxLen = 1, lastIdx = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (groups[i] != groups[j] &&
                    hamDist(words[j], words[i]) == 1) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        parent[i] = j;
                    }
                }
            }
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                lastIdx = i;
            }
        }

        vector<string> res;
        for (int i = lastIdx; i != -1; i = parent[i]) {
            res.push_back(words[i]);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
