class Solution {
public:
    int maximumLength(string s) {
        unordered_map<string, int> mp;
        int n = s.size();
        int ans = -1;

        for (int i = 0; i < n; i++) {
            string str = "";
            for (int j = i; j < n; j++) {
                str.push_back(s[j]);

                if (str.find_first_not_of(str[0]) == string::npos) {
                    mp[str]++;
                }
            }
        }

        for (auto& it : mp) {
            if (it.second >= 3) {
                ans = max(ans, (int)it.first.size());
            }
        }

        return ans;
    }
};
