class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words,
                                         vector<int>& groups) {
        vector<string> res;
        int flag = -1;
        int n = groups.size();

        for (int i = 0; i < n; i++)
            if (flag != groups[i])
                res.push_back(words[i]), flag = groups[i];

        return res;
    }
};