class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        if (n > m)
            return false;

        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        for (int i = 0; i < n; i++) {
            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }

        if (freq1 == freq2)
            return true;

        int left = 0;
        int right = n;

        while (right < m) {
            freq2[s2[left] - 'a']--;
            freq2[s2[right] - 'a']++;

            left++;
            right++;

            if (freq1 == freq2)
                return true;
        }
        return false;
    }
};