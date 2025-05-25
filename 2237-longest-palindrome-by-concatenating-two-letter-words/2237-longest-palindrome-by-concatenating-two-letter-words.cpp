class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        for (auto& w : words) {
            mp[w]++;
        }

        int cnt = 0;
        bool hasCenter = false;

        for (auto& it : mp) {
            string w = it.first;
            string rev = w;
            reverse(rev.begin(), rev.end());

            if (w == rev) {
                int pairs = mp[w] / 2;
                cnt += pairs * 4;
                if (mp[w] % 2 == 1) {
                    hasCenter = true;
                }
            } else if (mp.find(rev) != mp.end()) {
                int pairCount = min(mp[w], mp[rev]);
                cnt += pairCount * 4;
                mp[rev] = 0;
            }
        }

        if (hasCenter) {
            cnt += 2;
        }

        return cnt;
    }
};
