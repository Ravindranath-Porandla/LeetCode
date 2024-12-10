class Solution {
public:
    bool isPossible(string str) {
        char ch = str[0];
        int n = str.size();

        for (int i = 1; i < n; i++) {
            if (str[i] != ch) {
                return false;
            }
        }

        return true;
    }
    int maximumLength(string s) {
        unordered_map<string, int> mp;
        int n = s.size();
        int ans = -1;

        for (int i = 0; i < n; i++) {
            string str = "";
            for (int j = i; j < n; j++) {
                str.push_back(s[j]);

                if (isPossible(str)) {
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
