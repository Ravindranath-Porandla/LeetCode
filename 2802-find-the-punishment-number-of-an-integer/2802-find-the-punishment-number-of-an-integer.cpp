class Solution {
public:
    bool check(int i, int currentSum, string s, int num, vector<vector<int>>& dp) {

        if (i == s.size()) {
            return currentSum == num;
        }

        if (currentSum > num) {
            return false;
        }

        if(dp[i][currentSum] != -1){
            return dp[i][currentSum];
        }

        for (int j = i; j < s.size(); j++) {
            string sub_str = s.substr(i, j - i + 1);
            int val = stoi(sub_str);
            if (check(j + 1, currentSum + val, s, num, dp)) {
                return true;
            }
        }

        return false;
    }

public:
    int punishmentNumber(int n) {
        int punish = 0;

        for (int num = 1; num <= n; num++) {
            int sq = num * num;
            string val = to_string(sq);

            vector<vector<int>> dp(val.size(), vector<int>(num + 1, -1));

            if (check(0, 0, val, num, dp)) {
                punish += sq;
            }
        }

        return punish;
    }
};