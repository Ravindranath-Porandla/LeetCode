class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long int ans = 0;
        sort(skill.begin(), skill.end());

        int i = 0;
        int j = skill.size() - 1;
        int sum = skill[0] + skill[skill.size() - 1];

        while (i < j) {
            int curSum = skill[i] + skill[j];
            if (curSum != sum)
                return -1;
            ans += (skill[i] * skill[j]);
            i++;
            j--;
        }
        return ans;
    }
};