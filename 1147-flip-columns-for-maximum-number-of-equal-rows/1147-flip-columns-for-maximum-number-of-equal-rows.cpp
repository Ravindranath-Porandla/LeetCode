class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> mp;

        for (auto& row : matrix) {
            string temp = "";
            for (auto& col : row) {
                temp.push_back('0' + col);
            }
            mp[temp]++;
        }

        int ans = 0;

        for (auto& row : matrix) {
            string inverted = "";
            string current = "";
            for (auto& col : row) {
                current.push_back('0' + col);
            }

            for (auto& elem : current) {
                if (elem == '0') {
                    inverted.push_back('1');
                } else {
                    inverted.push_back('0');
                }
            }

            ans = max(ans, mp[current] + mp[inverted]);
        }

        return ans;
    }
};