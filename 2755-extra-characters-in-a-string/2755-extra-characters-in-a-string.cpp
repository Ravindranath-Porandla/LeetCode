class Solution {
    int dp[51];
    int solve(int i, string& s, vector<string>& dict) {
        if (i >= s.length())
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int currI = i;
        string curr = "";
        int mini = INT_MAX;

        for (; i < s.length(); i++) {
            curr += s[i];
            int currE = 0;

            if (find(dict.begin(), dict.end(), curr) == dict.end())
                currE = curr.length();

            int nextE = solve(i + 1, s, dict);
            mini = min(mini, currE + nextE);
        }

        return dp[currI] = mini;
    }

public:
    int minExtraChar(string s, vector<string>& dictionary) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        memset(dp, -1, sizeof(dp));
        return solve(0, s, dictionary);
    }
};